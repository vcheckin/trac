/*
 * trac.cpp
 */

#include <stdarg.h>
#include <WProgram.h>
#include <AFmotor/AFMotor.h>
#include <HardwareSerial.h>
#include "trac.h"
#include "Timer3/Timer3.h"

extern "C" {
#include "thread.h"
#include "melexis.h"
}

int a = 0;
static uint8_t stack[1024];

static void rt_entry()
{
	DBG("entered\n");
	while(1) {
		mlx_query_all();
		a++;
		yield();
	}
}

void setup() {
	Serial.begin(9600);
	DBG("setup\n");

	pinMode(13, OUTPUT);
	digitalWrite(13, 0);
	setup_mlx_spi();


	init_thread(0, rt_entry, stack, 1024);

	cli();          // disable global interrupts
	TCCR1A = 0;     // set entire TCCR1A register to 0
	TCCR1B = 0;     // same for TCCR1B

	// set compare match register to desired timer count:
	OCR1A = (F_CPU / 8) / 100;
	// turn on CTC mode:
	TCCR1B |= _BV(WGM12);
	// Set CS10 and CS12 bits for /1024
	// CS11 for /8
	TCCR1B |= _BV(CS11);
	//	enable timer compare interrupt:
	TIMSK1 |= (1 << OCIE1A);
	sei();

	DBG("inited\n");

}

void loop()
{
#if 1
//	int i;
//	uint32_t dt;
//	succ = 0;
//	for(i = 0; i < 25; i++) {
//		dt = micros();
//		mlx_query_all();
//		dt = micros() - dt;
//		// in simple tests 650us delay here gave about 50% success rate
//		// 700us -- 100% ok
//		delayMicroseconds(700);
//	}
//	DBG("queried all in %ld us, %d succ\n", dt, succ);
//	DBG("%d %d %d\n", mlx_sensors[0].alfa, mlx_sensors[0].beta, mlx_sensors[0].z);
//	DBG("a=%d\n", a);
	delay(1000);
	DBG("ovr=%ld dt=%ld\n", overruns, dt);
	DBG("crc=%d err=%d ntt=%d\n", crc_err, error, ntt);
	DBG("ticks=%d micros=%ld\n", a, micros());
	DBG("%d %d %d\n", mlx_sensors[0].alfa, mlx_sensors[0].beta, mlx_sensors[0].z);
#endif
	//
//  motor.run(FORWARD);      // turn it on going forward
//  delay(1000);
//
//  Serial.print("tock");
//  motor.run(BACKWARD);     // the other way
//  delay(1000);
//
//  Serial.print("tack");
//  motor.run(RELEASE);      // stopped
//  delay(1000);
}

#ifdef SIMULATED
static void simulavr_puts(const char *s)
{
	while(*s) {
		(*((volatile char *)0x38)) = *s++;
	}
}
#endif
void prints(const char *fmt, ... )
{
	char tmp[64]; // resulting string limited to 128 chars
	va_list args;
	va_start (args, fmt );
	vsnprintf(tmp, 128, fmt, args);
	va_end (args);
#ifndef SIMULATED
	Serial.print(tmp);
#else
	simulavr_puts(tmp);
#endif
}

void prints_P(const prog_char *fmtp, ... )
{
	char tmp[64]; // resulting string limited to 128 chars
	char fmt[64];
	va_list args;
	va_start (args, fmtp );
	strcpy_P(fmt, fmtp);
	vsnprintf(tmp, 128, fmt, args);
	va_end (args);
#ifndef SIMULATED
	Serial.print(tmp);
#else
	simulavr_puts(tmp);
#endif
}

/**
 * Output contents of buffer, filters non-printable chars
 *
 * @param buf	pointer to buffer
 * @param len	buffer length
 */
void dump_buffer(const char *buf, int len)
{
	// number of bytes per line
	int w = 16;
	char bufh[w * 3 + 1];
	char bufc[w + 1];
	int i, m;
	prints("data @ %p =", buf);
	for (i = 0, m = 0; i < len; i++, m = i % w) {
		if (m == 0)
			prints("\n%08lx: ", (unsigned long) buf + i);
		sprintf(bufh + m * 3, "%02x ", (unsigned char) buf[i]);
		sprintf(bufc + m, "%c",
			(buf[i] > 31 && buf[i] < 127) ? buf[i] : '.');
		if (m == w - 1)
			prints("%s  %s", bufh, bufc);
	}
	if (m != 0) {
		memset(bufh + m * 3, ' ', sizeof(bufh) - m * 3);
		bufh[sizeof(bufh) - 1] = 0;
		prints("%s  %s", bufh, bufc);
	}
	prints("\n");
}
