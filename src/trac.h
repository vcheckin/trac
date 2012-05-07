/*
 * trac.h
 */

#ifndef TRAC_H_
#define TRAC_H_

#include <WProgram.h>
#include <avr/pgmspace.h>
#ifdef __cplusplus
extern "C" {
#endif
void scr_setup ();
void scr_loop();
void prints(const char *fmt, ... );
void prints_P(const prog_char *fmtp, ... );
void dump_buffer(const char *buf, int len);
#ifdef __cplusplus
}
#endif
//#define DBG(fmt, arg...)
#define DBG(fmt, arg...) do { \
	PROGMEM static const prog_char __fmt[] = fmt; \
	prints_P(__fmt, ##arg);} while(0)

//#define DBG(fmt, arg...) do { \
	prints(fmt, ##arg);} while(0)

#endif /* TRAC_H_ */
