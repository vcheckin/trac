/*
 * melexis.h
 *
 */

#ifndef MELEXIS_H_
#define MELEXIS_H_

// devices on SPI bus
enum {
	MLX_WHEEL_FR = 0,
//	MLX_WHEEL_FL,
//	MLX_WHEEL_RR,
//	MLX_WHEEL_RL,
//	MLX_VLV_FR,
//	MLX_VLV_FL,
//	MLX_VLV_RR,
//	MLX_VLV_RL,
//	MLX_1,
//	MLX_2,
//	MLX_3,
//	MLX_4,
	MLX_MAX = 1,
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
extern volatile int error;
extern volatile int normal;

extern struct mlx_sensor mlx_sensors[MLX_MAX];

void mlx_query_all(void);

#endif /* MELEXIS_H_ */
