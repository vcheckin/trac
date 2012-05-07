/*
 * melexis.h
 *
 */

#ifndef MELEXIS_H_
#define MELEXIS_H_

// devices on SPI bus
enum {
	MLX_VLV_FR,
	MLX_VLV_FL,
	MLX_VLV_RR,
	MLX_VLV_RL,
	MLX_PRESS_A,
	MLX_PRESS_B,
	MLX_STEER,
	MLX_TREADLE,
	MLX_MAX,
};

struct message {
	byte bytes[8];
};

void setup_mlx_spi();

struct mlx_sensor {
	byte active;
	unsigned long timestamp;
	int alfa, beta, z;
};

// TODO should not be in public API

extern volatile long int dt;

extern volatile int crc_err;
extern volatile int ntt;
extern volatile int error_cnt;
extern volatile int normal;

extern struct mlx_sensor mlx_sensors[MLX_MAX];

void mlx_query_all(void);

#endif /* MELEXIS_H_ */
