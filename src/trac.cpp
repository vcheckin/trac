/*
 * trac.cpp
 */

#include <stdarg.h>
#include <WProgram.h>
#include <AFmotor/AFMotor.h>
#include <HardwareSerial.h>
#include "trac.h"
#include "melexis.h"
#include "Timer3/Timer3.h"

//AF_DCMotor motor(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm

int led_on = 1;

void isr()
{
	digitalWrite(13, digitalRead(13) ^ 1);
}

void setup() {
//	motor.setSpeed(200);     // set the speed to 200/255
	Serial.begin(9600);
	//scr_setup();
	setup_mlx_spi();
//	pinMode(13, OUTPUT);
//	digitalWrite(13, 0);
//	Timer1.initialize(50000); // microsecs
//	Timer1.attachInterrupt(isr);
}

void loop()
{
	int i;
	succ = 0;
	unsigned long mic = micros();
	for(i = 0; i < 100; i++) {
		mlx_query_all();
		// in simple tests 650us delay here gave about 50% success rate
		// 700us -- 100% ok
		delayMicroseconds(700);
	}
	prints("queried all in %ld us, %d succ\n", micros() - mic, succ);
	prints("%d %d\n", mlx_sensors[0].alfa, mlx_sensors[1].beta);
	delay(500);

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

void prints(const char *fmt, ... )
{
	char tmp[128]; // resulting string limited to 128 chars
	va_list args;
	va_start (args, fmt );
	vsnprintf(tmp, 128, fmt, args);
	va_end (args);
	Serial.print(tmp);
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
