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
	MLX_MAX,
};

struct message {
	byte bytes[8];
};

void setup_mlx_spi();
struct sensor {
	byte active;
	unsigned long timestamp;
	int alfa, beta, z;
};

extern int succ;
extern struct sensor mlx_sensors[MLX_MAX];
#endif /* MELEXIS_H_ */
