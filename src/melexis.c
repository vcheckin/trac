/*
 * melexis.cpp
 */
#include "trac.h"
#include "spi.h"
#include "melexis.h"

// hardware slave select pin on ATMEGA
#define SLAVE_SELECT 53

struct mlx_sensor mlx_sensors[MLX_MAX];

static const uint8_t crc_cba[256] = {
		0x00 ,0x2f ,0x5e ,0x71 ,0xbc ,0x93 ,0xe2 ,0xcd,
		0x57 ,0x78 ,0x09 ,0x26 ,0xeb ,0xc4 ,0xb5 ,0x9a,
		0xae ,0x81 ,0xf0 ,0xdf ,0x12 ,0x3d ,0x4c ,0x63,
		0xf9 ,0xd6 ,0xa7 ,0x88 ,0x45 ,0x6a ,0x1b ,0x34,
		0x73 ,0x5c ,0x2d ,0x02 ,0xcf ,0xe0 ,0x91 ,0xbe,
		0x24 ,0x0b ,0x7a ,0x55 ,0x98 ,0xb7 ,0xc6 ,0xe9,
		0xdd ,0xf2 ,0x83 ,0xac ,0x61 ,0x4e ,0x3f ,0x10,
		0x8a ,0xa5 ,0xd4 ,0xfb ,0x36 ,0x19 ,0x68 ,0x47,
		0xe6 ,0xc9 ,0xb8 ,0x97 ,0x5a ,0x75 ,0x04 ,0x2b,
		0xb1 ,0x9e ,0xef ,0xc0 ,0x0d ,0x22 ,0x53 ,0x7c,
		0x48 ,0x67 ,0x16 ,0x39 ,0xf4 ,0xdb ,0xaa ,0x85,
		0x1f ,0x30 ,0x41 ,0x6e ,0xa3 ,0x8c ,0xfd ,0xd2,
		0x95 ,0xba ,0xcb ,0xe4 ,0x29 ,0x06 ,0x77 ,0x58,
		0xc2 ,0xed ,0x9c ,0xb3 ,0x7e ,0x51 ,0x20 ,0x0f,
		0x3b ,0x14 ,0x65 ,0x4a ,0x87 ,0xa8 ,0xd9 ,0xf6,
		0x6c ,0x43 ,0x32 ,0x1d ,0xd0 ,0xff ,0x8e ,0xa1,
		0xe3 ,0xcc ,0xbd ,0x92 ,0x5f ,0x70 ,0x01 ,0x2e,
		0xb4 ,0x9b ,0xea ,0xc5 ,0x08 ,0x27 ,0x56 ,0x79,
		0x4d ,0x62 ,0x13 ,0x3c ,0xf1 ,0xde ,0xaf ,0x80,
		0x1a ,0x35 ,0x44 ,0x6b ,0xa6 ,0x89 ,0xf8 ,0xd7,
		0x90 ,0xbf ,0xce ,0xe1 ,0x2c ,0x03 ,0x72 ,0x5d,
		0xc7 ,0xe8 ,0x99 ,0xb6 ,0x7b ,0x54 ,0x25 ,0x0a,
		0x3e ,0x11 ,0x60 ,0x4f ,0x82 ,0xad ,0xdc ,0xf3,
		0x69 ,0x46 ,0x37 ,0x18 ,0xd5 ,0xfa ,0x8b ,0xa4,
		0x05 ,0x2a ,0x5b ,0x74 ,0xb9 ,0x96 ,0xe7 ,0xc8,
		0x52 ,0x7d ,0x0c ,0x23 ,0xee ,0xc1 ,0xb0 ,0x9f,
		0xab ,0x84 ,0xf5 ,0xda ,0x17 ,0x38 ,0x49 ,0x66,
		0xfc ,0xd3 ,0xa2 ,0x8d ,0x40 ,0x6f ,0x1e ,0x31,
		0x76 ,0x59 ,0x28 ,0x07 ,0xca ,0xe5 ,0x94 ,0xbb,
		0x21 ,0x0e ,0x7f ,0x50 ,0x9d ,0xb2 ,0xc3 ,0xec,
		0xd8 ,0xf7 ,0x86 ,0xa9 ,0x64 ,0x4b ,0x3a ,0x15,
		0x8f ,0xa0 ,0xd1 ,0xfe ,0x33 ,0x1c ,0x6d ,0x42,
};

/** CRC8, per MLX datasheet */
static uint8_t crc8(const uint8_t *data)
{
	uint8_t crc = 0xff;
	crc = crc_cba[crc ^ data[0]];
	crc = crc_cba[crc ^ data[1]];
	crc = crc_cba[crc ^ data[2]];
	crc = crc_cba[crc ^ data[3]];
	crc = crc_cba[crc ^ data[4]];
	crc = crc_cba[crc ^ data[5]];
	crc = crc_cba[crc ^ data[6]];
	return ~crc;
}

/* select sensor n -- for now with only one
 * directly connected to HW /SS pin
 */
static inline void select_sensor(int chip)
{
	if(chip == 0)
		digitalWrite(SLAVE_SELECT, LOW);
}

static inline void deselect_sensor(int chip)
{
	if(chip == 0)
		digitalWrite(SLAVE_SELECT, HIGH);
}

static inline int transfer_message(int chip, const struct message *out, struct message *in)
{
	int i;
	select_sensor(chip);
	for(i = 0; i < 8; i++) {
		in->bytes[i] = spi_transfer(out->bytes[i]);
	}
	deselect_sensor(chip);
	return (crc8(in->bytes) != in->bytes[7]);
}

struct message out = {{0}};
struct message in;

void init_proto()
{
	int i;
	// send a NOP challenge to every device
	out.bytes[2] = 0x5a; // key
	out.bytes[3] = 0xa5; // key
	out.bytes[6] = 0xd0; // NOP challenge, 1101 0000, opcode = 16
	out.bytes[7] = crc8(out.bytes);
	for(i = 0; i < MLX_MAX; i++) {
		if(transfer_message(i, &out, &in)) {
			DBG("invalid crc in initial reply from sensor %d\n", i);
		}
	}
	dump_buffer((const char *)(in.bytes), 8);

	// craft GET1 command
	// max data timeout is 65535 us, or 65.5 ms

	out.bytes[2] = 0xff; out.bytes[3] = 0xff;
	out.bytes[6] = (1 << 6) + 19; // marker = 1 (alpha + beta + diag), opcode = 19 (GET1)
	out.bytes[7] = crc8(out.bytes);
	for(i = 0; i < MLX_MAX; i++) {
		// send GET1, expect NOP reply
		if(transfer_message(i, &out, &in)) {
			DBG("invalid crc %x in NOP reply from sensor %d\n", in.bytes[7], i);
			dump_buffer((const char *)(in.bytes), 8);
		}
		if(in.bytes[2] != 0x5a || in.bytes[3] != 0xa5 ||
			in.bytes[4] != 0xa5 || in.bytes[5] != 0x5a )
		{
			DBG("invalid key, sensor %d\n", i);
			dump_buffer((const char *)(in.bytes), 8);
		}
	}

}

// setup SPI per mlx specs
void setup_mlx_spi()
{
	spi_begin();
	spi_setBitOrder(MSBFIRST);
	// CPOL=0 CPHA=1
	spi_setDataMode(SPI_MODE1);
	// datasheet says min clock period 1.8us
	// minimum time between two GETS is 1050 ms
	// With 3m UTP cable DIV8 was pretty stable
	// DIV4 didn't work.
	// 16Mhz / 32 = 500kHz


	// /128 dt=540us
	// /64 dt=284us
	// /32 dt=160
	// /16 dt=96
	// /8 =
	spi_setClockDivider(SPI_CLOCK_DIV128);
	init_proto();
}

volatile long int dt;
volatile int crc_err = 0;
volatile int ntt = 0;
volatile int error_cnt = 0;
volatile int normal = 0;
void mlx_query_all(void)
{
	int i;
	memset(&out, 0, 8);
	// craft GET1 command
	// max data timeout in us, or 65.5 ms
	out.bytes[2] = 0xff; out.bytes[3] = 0xff;
	out.bytes[6] = (0 << 6) + 19; // marker = 1 (alpha + beta + diag), opcode = 19 (GET1)
	out.bytes[7] = crc8(out.bytes);
	for(i = 0; i < MLX_MAX; i++) {
		int res;
		// send GET1, expect normal data packet
		dt = micros();
		res = transfer_message(i, &out, &in);
		dt = micros() - dt;
		if(res) {
			//prints("invalid crc\n");
			mlx_sensors[i].active = 0;
			crc_err++;
			continue;
		}
		// is this a regular packet?
		if((in.bytes[6] & 0xc0) != 0xc0)
			normal++;
		else
			in.bytes[6] == 0xfe ? ntt++ : error_cnt++;
//		dump_buffer((const char *)(out.bytes), 8);
//		dump_buffer((const char *)(in.bytes), 8);
		mlx_sensors[i].timestamp = micros();
		mlx_sensors[i].alfa = in.bytes[0] + ((in.bytes[1] & 0x3f) << 8);
		mlx_sensors[i].beta = in.bytes[2] + ((in.bytes[3] & 0x3f) << 8);
		mlx_sensors[i].z = in.bytes[4] + ((in.bytes[5] & 0x3f) << 8);
		if(in.bytes[1] & 0x20) mlx_sensors[i].alfa -= 16384;
		if(in.bytes[3] & 0x20) mlx_sensors[i].beta -= 16384;
		if(in.bytes[5] & 0x20) mlx_sensors[i].z -= 16384;
	}
}
