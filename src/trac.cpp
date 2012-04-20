/*
 * trac.cpp
 */

#include <WProgram.h>
#include <AFmotor/AFMotor.h>
#include <HardwareSerial.h>
#include "trac.h"
#include "melexis.h"

AF_DCMotor motor(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm

void setup() {
//	scr_setup();
//	motor.setSpeed(200);     // set the speed to 200/255
	Serial.begin(9600);
	Serial.print("inited\n");
	setup_mlx_spi();
}

void loop() {
//	scr_loop();
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
