/*
*/
#include <Arduino.h>

#if 1
static const byte Font5x9Mono[535] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x08, 0x42, 0x10, 0x04,
	0x00, 0x14, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x05, 0x7D, 0x4A,
	0xFA, 0x80, 0x02, 0x3E, 0x8E, 0x2F, 0x88, 0x00, 0x02, 0x22,
	0x22, 0x22, 0x00, 0x01, 0x14, 0xA2, 0x2B, 0x26, 0x80, 0x04,
	0x22, 0x00, 0x00, 0x00, 0x00, 0x11, 0x08, 0x42, 0x10, 0x82,
	0x02, 0x08, 0x42, 0x10, 0x84, 0x40, 0x00, 0x4A, 0xBA, 0xA4,
	0x00, 0x00, 0x02, 0x13, 0xE4, 0x20, 0x00, 0x00, 0x00, 0x00,
	0x01, 0x08, 0x80, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x02, 0x00, 0x00, 0x08, 0x88, 0x88, 0x00, 0x00,
	0x74, 0x67, 0x5C, 0xC5, 0xC0, 0x01, 0x18, 0x42, 0x10, 0x8E,
	0x00, 0x1D, 0x10, 0x99, 0x10, 0xF8, 0x00, 0xE8, 0x84, 0xC1,
	0x8B, 0x80, 0x01, 0x19, 0x52, 0xF8, 0x84, 0x00, 0x7E, 0x1E,
	0x08, 0x62, 0xE0, 0x01, 0xD0, 0xF4, 0x63, 0x17, 0x00, 0x1F,
	0x08, 0x88, 0x84, 0x20, 0x00, 0x74, 0x62, 0xE8, 0xC5, 0xC0,
	0x03, 0xA3, 0x18, 0xBC, 0x2E, 0x00, 0x00, 0x02, 0x00, 0x04,
	0x00, 0x00, 0x00, 0x10, 0x00, 0x21, 0x10, 0x00, 0x08, 0x88,
	0x20, 0x80, 0x00, 0x00, 0x1F, 0x07, 0xC0, 0x00, 0x00, 0x08,
	0x20, 0x88, 0x80, 0x00, 0x0E, 0x88, 0x44, 0x40, 0x10, 0x00,
	0x03, 0xA3, 0x5B, 0xC1, 0xC0, 0x01, 0x15, 0x18, 0xFE, 0x31,
	0x00, 0x3D, 0x18, 0xFA, 0x31, 0xF0, 0x00, 0xE8, 0xC2, 0x10,
	0x8B, 0x80, 0x0E, 0x4A, 0x31, 0x8C, 0xB8, 0x00, 0x7E, 0x10,
	0xF4, 0x21, 0xF0, 0x03, 0xF0, 0x87, 0xA1, 0x08, 0x00, 0x0E,
	0x8C, 0x21, 0x38, 0xB8, 0x00, 0x8C, 0x63, 0xF8, 0xC6, 0x20,
	0x03, 0x88, 0x42, 0x10, 0x8E, 0x00, 0x1E, 0x21, 0x08, 0x52,
	0x60, 0x01, 0x19, 0x53, 0x14, 0x94, 0x40, 0x08, 0x42, 0x10,
	0x84, 0x3E, 0x00, 0x47, 0x75, 0xAC, 0x63, 0x10, 0x02, 0x39,
	0xAD, 0x6B, 0x38, 0x80, 0x0E, 0x8C, 0x63, 0x18, 0xB8, 0x00,
	0xF4, 0x63, 0x1F, 0x42, 0x00, 0x03, 0xA3, 0x18, 0xD6, 0x4D,
	0x00, 0x3D, 0x18, 0xC7, 0xD1, 0x88, 0x00, 0xE8, 0xC1, 0xC1,
	0x8B, 0x80, 0x0F, 0x90, 0x84, 0x21, 0x08, 0x00, 0x46, 0x31,
	0x8C, 0x62, 0xE0, 0x02, 0x31, 0x8A, 0x94, 0x42, 0x00, 0x11,
	0x8C, 0x6B, 0x55, 0x28, 0x00, 0x8C, 0x54, 0x45, 0x46, 0x20,
	0x04, 0x63, 0x15, 0x10, 0x84, 0x00, 0x3E, 0x11, 0x11, 0x10,
	0xF8, 0x00, 0x62, 0x10, 0x84, 0x21, 0x0C, 0x00, 0x41, 0x04,
	0x10, 0x40, 0x00, 0x30, 0x84, 0x21, 0x08, 0x46, 0x00, 0x8A,
	0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x00,
	0x21, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC1, 0x3A, 0x4E,
	0x00, 0x21, 0x0E, 0x4A, 0x52, 0xE0, 0x00, 0x00, 0x3A, 0x10,
	0x83, 0x80, 0x01, 0x09, 0xD2, 0x94, 0x9C, 0x00, 0x00, 0x0C,
	0x97, 0x20, 0xE0, 0x00, 0xC8, 0x47, 0x10, 0x84, 0x00, 0x00,
	0x03, 0x25, 0x29, 0x38, 0x4C, 0x84, 0x39, 0x29, 0x4A, 0x40,
	0x01, 0x00, 0x42, 0x10, 0x84, 0x00, 0x08, 0x02, 0x10, 0x84,
	0x21, 0x11, 0x08, 0x4A, 0x98, 0xA4, 0x80, 0x02, 0x10, 0x84,
	0x21, 0x04, 0x00, 0x00, 0x1A, 0xAD, 0x6B, 0x50, 0x00, 0x00,
	0xE4, 0xA5, 0x29, 0x00, 0x00, 0x03, 0x25, 0x29, 0x30, 0x00,
	0x00, 0x39, 0x29, 0x4B, 0x90, 0x80, 0x00, 0xE9, 0x4A, 0x4E,
	0x10, 0x80, 0x0B, 0x62, 0x10, 0x80, 0x00, 0x00, 0x32, 0x0C,
	0x17, 0x00, 0x04, 0x23, 0x88, 0x42, 0x08, 0x00, 0x00, 0x12,
	0x94, 0xA4, 0xE0, 0x00, 0x00, 0x94, 0xA5, 0x44, 0x00, 0x00,
	0x04, 0x63, 0x5A, 0xA8, 0x00, 0x00, 0x22, 0xA2, 0x2A, 0x20,
	0x00, 0x01, 0x29, 0x4A, 0x4E, 0x13, 0x00, 0x0F, 0x11, 0x10,
	0xF0, 0x00, 0x22, 0x11, 0x04, 0x21, 0x04, 0x02, 0x10, 0x84,
	0x21, 0x08, 0x00, 0x20, 0x84, 0x11, 0x08, 0x44, 0x01, 0x54,
	0x00, 0x00, 0x00, 0x00, 0x00
}; /* 535 bytes */

#if 0

/* 4-bit serial communication LDS183 LCD module */

const int SCOMMAND = 0;
const int SDATA = 1;
const int DC = 4;
const int CS = 2;
const int SDA = 6;
const int RESET = 3;
const int CLK = 5;


#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))

byte gr;
byte gg;
byte gb;

void scr_setup () {
  DDRD = 0x7C;
  lcdInit();
}

void lcdInit() {

  cbi(PORTD, CS);
  cbi(PORTD, SDA);
  sbi(PORTD, CLK);

  sbi(PORTD, RESET);
  cbi(PORTD, RESET);
  sbi(PORTD, RESET);

  sbi(PORTD, CLK);
  sbi(PORTD, SDA);
  sbi(PORTD, CLK);

  delay(10);

  //Software Reset
  sendCMD(0x01);

  // Write Contrast
  sendCMD(0x25);
  sendData(64);

  //Sleep Out and booster on
  sendCMD(0x11);

  // Booster on
  //sendCMD(0x03);

  delay(10);

  // Display Inversion off
  sendCMD(0x20);

  // Idle Mode off
  sendCMD(0x38);

  // Display on
  sendCMD(0x29);

  // Normal Mode on
  sendCMD(0x13);

  // Memory Data Access control
  sendCMD(0x36);
  sendData(0x60);
  // sendData(0x00);
  //sendData(8|128);

  sendCMD(0x3A);
  sendData(5);   //16-Bit per Pixel

 // Color set
  // sendCMD(0x2D);
  // sendDATA(0x00);

  // X_Address or Column Address Area
  sendCMD(0x2A);
  sendData(0);
  sendData(127);

  // Frame Frequency Select
  sendCMD(0xB4);
  sendData(0x03);
  sendData(0x08);
  sendData(0x0b);
  sendData(0x0e);

  // Display Control
  sendCMD(0xBA);
  sendData(0x07);
  sendData(0x0D);

  //Page Adress Set
  sendCMD(0x2B);
  sendData(0);
  sendData(127);
}

void scr_loop() {
  //Memory Write
  sendCMD(0x2C);

  int i, j, k, l;

  // black background
  for (i=0; i<128*128; i++) {
      setPixel(0, 0, 0);
  }

  //Memory Write
  sendCMD(0x2C);

  setColor(0, 255, 0);

  printString("NKC Electronics", 15, 0);
  printString("Arduino One Stop Shop", 0, 20);

  setXY(40, 40, 40, 40);

  for (i=0; i<40*40; i++)
    setPixel(0, 0, 255);

  setXY(50, 50, 40, 40);

  for (i=0; i<40*40; i++)
    setPixel(255, 255, 255);

  setXY(60, 60, 40, 40);

  for (i=0; i<40*40; i++)
    setPixel(255, 0, 255);

  setXY(70, 70, 40, 40);

  for (i=0; i<40*40; i++)
    setPixel(100, 200, 10);

  setXY(40, 90, 20, 20);

  for (i=0; i<32; i++)
    for (j=0; j<64; j++)
      for (k=0; k<32; k++) {
        for (l=0; l<20*20; l++)
          setPixel(i<<3, j<<2, k<<3);
        setXY(20, 90, 20, 20);
      }

  while (1) ;
}

void shiftBits(byte b, int dc) {

  cbi(PORTD, CLK);
  if ((b&128)!=0)
    sbi(PORTD, SDA);
  else
    cbi(PORTD, SDA);
  sbi(PORTD, CLK);

  cbi(PORTD, CLK);
  if ((b&64)!=0)
    sbi(PORTD, SDA);
  else
    cbi(PORTD, SDA);
  sbi(PORTD, CLK);

  cbi(PORTD, CLK);
  if ((b&32)!=0)
    sbi(PORTD, SDA);
  else
    cbi(PORTD, SDA);
  sbi(PORTD, CLK);

  cbi(PORTD, CLK);
  if ((b&16)!=0)
    sbi(PORTD, SDA);
  else
    cbi(PORTD, SDA);
  sbi(PORTD, CLK);

  cbi(PORTD, CLK);
  if ((b&8)!=0)
    sbi(PORTD, SDA);
  else
    cbi(PORTD, SDA);
  sbi(PORTD, CLK);

  cbi(PORTD, CLK);
  if ((b&4)!=0)
    sbi(PORTD, SDA);
  else
    cbi(PORTD, SDA);
  sbi(PORTD, CLK);

  cbi(PORTD, CLK);
  if ((b&2)!=0)
    sbi(PORTD, SDA);
  else
    cbi(PORTD, SDA);
  sbi(PORTD, CLK);

  cbi(PORTD, CLK);
  if ((b&1)!=0)
    sbi(PORTD, SDA);
  else
    cbi(PORTD, SDA);
  if (dc == SDATA)
    sbi(PORTD, DC);
  else
    cbi(PORTD, DC);
  sbi(PORTD, CLK);
}

//send data
void sendData(byte data) {
  shiftBits(data, SDATA);
}

//send cmd
void sendCMD(byte data) {
  shiftBits(data, SCOMMAND);
}

void setXY(byte x, byte y, byte dx, byte dy) {
  sendCMD(0x2A);
  sendData(x);
  sendData(x+dx-1);

  sendCMD(0x2B);
  sendData(y);
  sendData(y+dy-1);

  sendCMD(0x2C);
}

//converts a 3*8Bit-RGB-Pixel to the 2-Byte-RGBRGB 565 Format of the Display
void setPixel(byte r,byte g,byte b) {
   sendData((r&248)|g>>5);
   sendData((g&7)<<5|b>>3);
}

void printString(char *st, byte x, byte y) {
  int stl, i;

  stl = strlen(st);

  for (i=0; i<stl; i++)
    printChar(*st++, x + (i*6), y);
}

void printChar(byte c, byte x, byte y) {
  byte bitmask, *pf, bitstart = 128;
  int cindex, iFont, count;

  setXY(x, y, 5, 9);

  iFont = (c - ' ') * 45 / 8;

  bitstart = 128 >> (((c - ' ') * 45) % 8);

  pf = &Font5x9Mono[iFont];

  count = 0;

  for (cindex=0; cindex<6; cindex++) {
    for (bitmask=bitstart; bitmask>0; bitmask=bitmask>>1) {
       if (count > 45) return;
       if (*pf&bitmask)
         setPixel(gr, gg, gb);
       else
         setPixel(0, 0, 0);
       count++;
    }
    bitstart = 128;
    pf++;
  }
}

void setColor(byte r, byte g, byte b) {
  gr = r;
  gg = g;
  gb = b;
}
#else
/*
 * screen.c
 *
 *  Created on: Apr 19, 2012
 *      Author: cve
 */
#include <Arduino.h>
/*

  Fry LCD test sketch
  2010 NKC Electronics

*/

/* 4-bit serial communication LDS183 LCD module */
const int SCOMMAND = 0;
const int SDATA = 1;
const int DC = 4;
const int CS = 2;
#define SDA 6
const int RESET = 3;
const int CLK = 5;

byte gr;
byte gg;
byte gb;

void scr_setup ()
{

  pinMode(DC, OUTPUT);
  pinMode(CS, OUTPUT);
  pinMode(SDA, OUTPUT);
  pinMode(RESET, OUTPUT);
  pinMode(CLK, OUTPUT);

  lcdInit();
}

void lcdInit() {

  digitalWrite(CS, 0);
  digitalWrite(SDA, 0);
  digitalWrite(CLK, 1);

  digitalWrite(RESET, 1);
  digitalWrite(RESET, 0);
  digitalWrite(RESET, 1);

  digitalWrite(CLK, 1);
  digitalWrite(SDA, 1);
  digitalWrite(CLK, 1);

  delay(10);

  //Software Reset
  sendCMD(0x01);

  // Write Contrast
  sendCMD(0x25);
  sendData(64);

  //Sleep Out and booster on
  sendCMD(0x11);

  // Booster on
  //sendCMD(0x03);

  delay(10);

  // Display Inversion off
  sendCMD(0x20);

  // Idle Mode off
  sendCMD(0x38);

  // Display on
  sendCMD(0x29);

  // Normal Mode on
  sendCMD(0x13);

  // Memory Data Access control
  sendCMD(0x36);
  sendData(0x60);
  // sendData(0x00);
  //sendData(8|128);

  sendCMD(0x3A);
  sendData(5);   //16-Bit per Pixel

 // Color set
  // sendCMD(0x2D);
  // sendDATA(0x00);

  // X_Address or Column Address Area
  sendCMD(0x2A);
  sendData(0);
  sendData(127);

  // Frame Frequency Select
  sendCMD(0xB4);
  sendData(0x03);
  sendData(0x08);
  sendData(0x0b);
  sendData(0x0e);

  // Display Control
  sendCMD(0xBA);
  sendData(0x07);
  sendData(0x0D);

  //Page Adress Set
  sendCMD(0x2B);
  sendData(0);
  sendData(127);
}

void scr_loop() {
  //Memory Write
  sendCMD(0x2C);

  int i, j, k, l;

  // black background
  for (i=0; i<128*128; i++) {
      setPixel(0, 0, 0);
  }
  //Test-Picture

  //red bar
//  for (i=0;i<128*32;i++) {
//    setPixel(255,0,0);
//  }

  //green bar
//  for (i=0;i<128*32;i++) {
//    setPixel(0,255,0);
//  }

  //blue bar
//  for (i=0;i<128*32;i++) {
//    setPixel(0,0,255);
//  }

  //white bar
//  for (i=0;i<128*32;i++) {
//    setPixel(255,255,255);
//  }


  // Vertical bar

  // X_Address or Column Address Area
//  sendCMD(0x2A);
//  sendData(0x2c);
//  sendData(0x54);

  //Page Adress Set
//  sendCMD(0x2B);
//  sendData(0);
//  sendData(127);

  //Memory Write
  sendCMD(0x2C);

//  for (i=0;i<41*128;i++) {
//    setPixel(255,20,147);
//  }

//  for (i=0; i<128; i++) {
//    setXY(i,i, 1, 1);
//    setPixel(0,0,0);
//  }

//  for (i=127; i>=0; i--) {
//    setXY(i,127-i, 1, 1);
//    setPixel(255, 255, 0);
//  }

  setColor(0, 255, 0);

  printString("NKC Electronics", 15, 0);
  printString("Arduino One Stop Shop", 0, 20);

  setXY(40, 40, 40, 40);

  for (i=0; i<40*40; i++)
    setPixel(0, 0, 255);

  setXY(50, 50, 40, 40);

  for (i=0; i<40*40; i++)
    setPixel(255, 255, 255);

  setXY(60, 60, 40, 40);

  for (i=0; i<40*40; i++)
    setPixel(255, 0, 255);

  setXY(70, 70, 40, 40);

  for (i=0; i<40*40; i++)
    setPixel(100, 200, 10);

  setXY(40, 90, 20, 20);

  for (i=0; i<32; i++)
    for (j=0; j<64; j++)
      for (k=0; k<32; k++) {
        for (l=0; l<20*20; l++)
          setPixel(i<<3, j<<2, k<<3);
        setXY(20, 90, 20, 20);
      }

  while (1) ;
}

void shiftBits(byte b, int dc) {
    digitalWrite(CLK, 0);
    if ((b&128)!=0)
      digitalWrite(SDA, 1);
    else
      digitalWrite(SDA, 0);
    digitalWrite(CLK, 1);

    digitalWrite(CLK, 0);
    if ((b&64)!=0)
      digitalWrite(SDA, 1);
    else
      digitalWrite(SDA, 0);
    digitalWrite(CLK, 1);

    digitalWrite(CLK, 0);
    if ((b&32)!=0)
      digitalWrite(SDA, 1);
    else
      digitalWrite(SDA, 0);
    digitalWrite(CLK, 1);

    digitalWrite(CLK, 0);
    if ((b&16)!=0)
      digitalWrite(SDA, 1);
    else
      digitalWrite(SDA, 0);
    digitalWrite(CLK, 1);

    digitalWrite(CLK, 0);
    if ((b&8)!=0)
      digitalWrite(SDA, 1);
    else
      digitalWrite(SDA, 0);
    digitalWrite(CLK, 1);

    digitalWrite(CLK, 0);
    if ((b&4)!=0)
      digitalWrite(SDA, 1);
    else
      digitalWrite(SDA, 0);
    digitalWrite(CLK, 1);

    digitalWrite(CLK, 0);
    if ((b&2)!=0)
      digitalWrite(SDA, 1);
    else
      digitalWrite(SDA, 0);
    digitalWrite(CLK, 1);

    digitalWrite(CLK, 0);
    if ((b&1)!=0)
      digitalWrite(SDA, 1);
    else
      digitalWrite(SDA, 0);

      if (dc == SDATA)
        digitalWrite(DC, 1);
      else
        digitalWrite(DC, 0);
    digitalWrite(CLK, 1);
}

//send data
void sendData(byte data) {
  shiftBits(data, SDATA);
}

//send cmd
void sendCMD(byte data) {
  shiftBits(data, SCOMMAND);
}

void setXY(byte x, byte y, byte dx, byte dy) {
  sendCMD(0x2A);
  sendData(x);
  sendData(x+dx-1);

  sendCMD(0x2B);
  sendData(y);
  sendData(y+dy-1);

  sendCMD(0x2C);
}

//converts a 3*8Bit-RGB-Pixel to the 2-Byte-RGBRGB 565 Format of the Display
void setPixel(byte r,byte g,byte b) {
   sendData((r&248)|g>>5);
   sendData((g&7)<<5|b>>3);
}

void printString(char *st, byte x, byte y) {
  int stl, i;

  stl = strlen(st);

  for (i=0; i<stl; i++)
    printChar(*st++, x + (i*6), y);
}

void printChar(byte c, byte x, byte y) {
  byte bitmask, *pf, bitstart = 128;
  int cindex, iFont, count;

  setXY(x, y, 5, 9);

  iFont = (c - ' ') * 45 / 8;

  bitstart = 128 >> (((c - ' ') * 45) % 8);

  pf = &Font5x9Mono[iFont];

  count = 0;

  for (cindex=0; cindex<6; cindex++) {
    for (bitmask=bitstart; bitmask>0; bitmask=bitmask>>1) {
       if (count > 45) return;
       if (*pf&bitmask)
         setPixel(gr, gg, gb);
       else
         setPixel(0, 0, 0);
       count++;
    }
    bitstart = 128;
    pf++;
  }
}

void setColor(byte r, byte g, byte b) {
  gr = r;
  gg = g;
  gb = b;
}


#endif
#endif
