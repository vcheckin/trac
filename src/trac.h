/*
 * trac.h
 */

#ifndef TRAC_H_
#define TRAC_H_

#include <WProgram.h>

#include <HardwareSerial.h>

extern "C" {
void scr_setup ();
void scr_loop();
}
void prints(const char *fmt, ... );
void dump_buffer(const char *buf, int len);
void mlx_query_all(void);
#endif /* TRAC_H_ */
