/**
 *  @filename   :   imagedata.cpp
 *  @brief      :   data file for epd demo
 *
 *  Copyright (C) Waveshare     August 22 2017
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documnetation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to  whom the Software is
 * furished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef _BitmapWaveshare_H_
#define _BitmapWaveshare_H_

#if defined(ESP8266) || defined(ESP32)
#include <pgmspace.h>
#else
#include <avr/pgmspace.h>
#endif

const unsigned char BitmapWaveshare_black[] PROGMEM = { /* 0X00,0X01,0X68,0X00,0XD4,0X00, */
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XBF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XCF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF8,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0X07,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,0XFF,0XFF,
0XC3,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC7,0XFF,0XFF,0XC0,0X3F,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,0XFF,0XFF,0XE0,0X0F,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XE7,0XFF,0XFF,0XF0,0X07,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XE7,0XFF,0XFF,0XF8,0X07,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,0XFF,
0XFF,0XFC,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,0XFF,0XFF,0XFE,0X01,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,0XFF,0XFF,0XFF,0X80,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XE7,0XFF,0XFF,0XFF,0XC0,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,
0XFF,0XFF,0XFF,0XC0,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,0XFF,0XFF,0XFF,
0XE0,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,0XFF,0XFF,0XFF,0XE0,0X7F,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,0XFF,0XFF,0XFF,0XE0,0X7F,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XE7,0XFF,0XFF,0XFF,0XF0,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XE7,0XFF,0XFF,0XFF,0XF0,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,0XFF,0XFF,
0XFF,0XF0,0X7F,0XDF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,0XFF,0XFF,0XFF,0XF0,0X7F,
0XBF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,0XFF,0XFF,0XFF,0XF0,0X7E,0X7F,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XE7,0XFF,0XFF,0XFF,0XF0,0X7E,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XE7,0XFF,0XFF,0XFF,0XF0,0X7C,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,0XFF,
0XFF,0XFF,0XF0,0X7D,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,0XFF,0XFC,0X03,0XE0,
0XFD,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,0XFF,0XF8,0X00,0XE0,0X79,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,0XFF,0XF0,0X00,0X60,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XE7,0XFF,0XE0,0X00,0X30,0XF8,0X00,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,
0XFF,0XC0,0X60,0X11,0X80,0X00,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,0XFF,0X00,0X30,
0X19,0X00,0X00,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,0XFE,0X40,0X20,0X08,0X00,0X00,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,0XC1,0XC0,0X00,0X08,0X00,0X7F,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XE7,0X80,0XC0,0X20,0X08,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XE7,0X00,0X4C,0X20,0X08,0X07,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE6,0X10,0X04,
0X20,0X00,0X1D,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE6,0X10,0X04,0X20,0X40,0X7C,
0XFF,0XF9,0XFF,0XFF,0XFF,0XFF,0XFF,0XE4,0X10,0X00,0X00,0X80,0XFC,0XFF,0XE0,0X7F,
0XFF,0XFF,0XFF,0XFF,0XE4,0X0C,0X00,0X03,0X0F,0XFC,0X7F,0XE4,0X3F,0XFF,0XFF,0XFF,
0XFF,0XE4,0X0E,0X00,0XC0,0X1F,0XFC,0X7F,0XC0,0X1F,0XFF,0XFF,0XFF,0XFF,0XE4,0X0B,
0X83,0XE0,0X0F,0XFC,0X7F,0XC2,0X1F,0XFF,0XFF,0XFF,0XFF,0XE6,0X00,0X07,0XF0,0X0F,
0XFE,0X7F,0XC1,0X0F,0XFF,0XFF,0XFF,0XFF,0XE6,0X00,0X07,0XF0,0X07,0XFE,0X7F,0XC0,
0X8F,0XFF,0XFF,0XFF,0XFF,0XE7,0X00,0X07,0XF0,0X03,0XFE,0X7F,0XE0,0X7F,0XFF,0XFF,
0XFF,0XFF,0XE7,0X80,0X03,0XF3,0X01,0XFE,0X7F,0XE0,0X1F,0XFF,0XFF,0XFF,0XFF,0XE7,
0XC0,0X03,0XE3,0X80,0XFE,0X7F,0XF0,0X1F,0XFF,0XFF,0XFF,0XFF,0XE7,0XF8,0X00,0XC0,
0XE0,0XFC,0X7F,0XF0,0X87,0XFF,0XFF,0XFF,0XFF,0XE7,0XF7,0X00,0X00,0X3C,0XFC,0X7F,
0XF0,0X83,0XFF,0XFF,0XFF,0XFF,0XE7,0XF9,0X80,0X00,0X18,0XFC,0XFF,0XF0,0X81,0XFF,
0XFF,0XFF,0XFF,0XE7,0X9D,0X80,0X04,0X00,0XFC,0XFF,0XF1,0XC1,0XFF,0XFF,0XFF,0XFF,
0XE6,0X35,0X01,0X04,0X00,0XFD,0XFF,0XF3,0X71,0XFF,0XFF,0XFF,0XFF,0XE6,0X62,0X02,
0X00,0X00,0XFD,0XFF,0XE2,0X01,0XFF,0XFF,0XFF,0XFF,0XE4,0XC2,0X02,0X00,0X00,0XFB,
0XFF,0XE2,0X01,0XFF,0XFF,0XFF,0XFF,0XE5,0X82,0X02,0X00,0X01,0XF3,0XFF,0XE0,0X01,
0XFF,0XFF,0XFF,0XFF,0XE3,0X01,0X0E,0X00,0X03,0XF3,0XFF,0XE4,0X01,0XFF,0XFF,0XFF,
0XFF,0XE6,0X01,0X83,0X00,0X7F,0XE7,0XFF,0XC0,0X00,0XFF,0XFF,0XFF,0XFF,0XE4,0X01,
0X81,0X00,0XFF,0XCF,0XFF,0XE0,0X00,0X3F,0XFF,0XFF,0XFF,0XE0,0X01,0X80,0X00,0XFF,
0X8F,0XFF,0XE0,0X00,0X1F,0XFF,0XFF,0XFF,0XE0,0X03,0XC0,0X01,0XFF,0X9F,0XFF,0XE0,
0X01,0X1F,0XFF,0XFF,0XFF,0XE0,0X0F,0XF8,0X01,0XFF,0XDF,0XFF,0XFC,0X16,0X1F,0XFF,
0XFF,0XFF,0XE0,0X1F,0XF0,0XC7,0XF8,0X3F,0XFF,0XF6,0X1F,0X1F,0XFF,0XFF,0XFF,0XE0,
0X3F,0XC0,0X6F,0XF0,0X1F,0XFF,0XE2,0X01,0X1F,0XFF,0XFF,0XFF,0XE0,0X7F,0XC0,0X3F,
0XC0,0X0F,0XFF,0XCC,0X00,0X9F,0XFF,0XFF,0XFF,0XE0,0XFF,0XC0,0X1F,0XC0,0X0F,0XFF,
0XDE,0X00,0X19,0XFF,0XFF,0XFF,0XE0,0XFF,0X80,0X0F,0X80,0X0F,0XFF,0X9F,0X00,0X00,
0XFF,0XFF,0XFF,0XE1,0XFF,0X80,0X40,0X00,0X07,0XFF,0X9F,0XFE,0X00,0XFF,0XFF,0XFF,
0XF3,0XFF,0X80,0XC0,0X00,0X07,0XFF,0XBF,0XFF,0X00,0X7F,0XFF,0XFF,0XE7,0XFF,0XC0,
0X80,0X00,0X07,0XFF,0XBF,0XFF,0X90,0X7F,0XFF,0XFF,0XE7,0XFF,0XC7,0X80,0X00,0X0F,
0XFF,0XBF,0XFF,0XD8,0X7F,0XFF,0XFF,0XE7,0XFF,0XE0,0XC0,0X00,0X3F,0XFF,0X3F,0XFF,
0XE0,0X7F,0XFF,0XFF,0XE7,0XFF,0XE0,0XC0,0X00,0X1F,0XFF,0X3F,0XFF,0XF0,0XFF,0XFF,
0XFF,0XE7,0XFF,0XF0,0X20,0X80,0X07,0XFF,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,0XFF,
0XE0,0X30,0X00,0X03,0XFF,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,0XFF,0XC0,0X30,0X40,
0X03,0XFF,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,0XFC,0X40,0X10,0X60,0X03,0XFF,0X7F,
0XFF,0XFF,0XFF,0XFF,0XFF,0XE7,0XE0,0XC0,0X18,0X3C,0X07,0XFE,0X7F,0XFF,0XFF,0XFF,
0XFF,0XFF,0XE7,0X87,0XC0,0X08,0X18,0X0F,0XFC,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XF7,
0X0F,0XE0,0X08,0X10,0X1F,0XFC,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF6,0X7F,0XFE,0X0C,
0X10,0X43,0XF9,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0XFF,0XF1,0X04,0X10,0X81,0XF3,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF1,0XFF,0XE1,0X04,0X11,0X81,0XE3,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XF3,0XFF,0XC0,0X06,0X11,0X80,0X4F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XF3,0XFF,0XC0,0X02,0X10,0X00,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF7,0XFF,0XC0,
0X22,0X10,0X08,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF7,0XFF,0XC0,0X3A,0X30,0X0C,
0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF7,0XFF,0XC2,0X18,0X00,0X0C,0X7F,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XF7,0XFF,0XC3,0X10,0X00,0X1C,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XF7,0XFF,0XC1,0X80,0X00,0X60,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF7,0XFF,
0X80,0XC0,0X00,0XC0,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF7,0XFF,0X80,0XC0,0X01,
0X80,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF7,0XF0,0X00,0X30,0X00,0X00,0X1F,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XF7,0X03,0XE0,0X00,0XE0,0X00,0X1F,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XF6,0X0F,0XF0,0X01,0XF0,0X02,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,
0XFF,0XF8,0X03,0XF8,0X3C,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF1,0XE0,0X04,0X07,
0XF8,0X00,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF3,0X80,0X02,0X07,0XF8,0X00,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF6,0X0F,0XFE,0X07,0XF8,0X01,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XF0,0X7F,0XFC,0X03,0XF8,0X03,0XBF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XF1,0XE0,0X10,0X21,0XF0,0X03,0X27,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF3,0X07,0XC0,
0XC0,0X60,0X81,0X91,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X3F,0XC1,0X00,0X00,0XC1,
0XD8,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X7F,0X87,0X04,0X00,0X60,0X4C,0X3F,0XFF,
0XFF,0XFF,0XFF,0XFF,0XF3,0XFF,0X86,0X0C,0X00,0X20,0X4F,0X3F,0XFF,0XFF,0XFF,0XFF,
0XFF,0XF7,0XFF,0X80,0X18,0X08,0X10,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF7,0XFF,
0XC0,0X18,0X08,0X08,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF7,0XFF,0XC0,0X10,0X4C,
0X0F,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF7,0X00,0X40,0X00,0X44,0X0C,0X3F,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X0C,0X46,0X0C,0X3F,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XF0,0X00,0X30,0X1C,0XC6,0X0C,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF1,
0XFF,0XF8,0XF8,0XC6,0X0C,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X1C,0X00,
0XC6,0X0C,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X0C,0X00,0XC3,0X00,0X3F,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF3,0X80,0X18,0X00,0XC3,0X00,0X3F,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XF7,0XFF,0X70,0X00,0XC1,0X00,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XF7,0XFF,0XE0,0X00,0XC3,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF3,0XFF,0XC0,
0X00,0XC7,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF1,0XFF,0X80,0X00,0XC6,0X07,
0X9F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X7F,0XC0,0X08,0XC4,0X03,0X0F,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XF0,0X0F,0XC0,0X18,0XC0,0X03,0X47,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XF3,0X83,0X80,0X20,0XC0,0X02,0X39,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0XE0,
0XC0,0X00,0XC0,0X02,0X0C,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X1C,0X40,0X43,0X70,
0XFC,0X03,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X0F,0X20,0XC2,0X31,0XEC,0X03,0X8F,
0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X03,0X9F,0XC4,0X03,0XFF,0X00,0XC7,0XFF,0XFF,0XFF,
0XFF,0XFF,0XF0,0X00,0X6F,0XE0,0X07,0X3F,0X80,0X63,0XFF,0XFF,0XFF,0XFF,0XFF,0XF7,
0X00,0X31,0XE0,0X04,0XFF,0XC0,0X31,0XFF,0XFF,0XFF,0XFF,0XFF,0XF7,0XE0,0X18,0XF0,
0X01,0XFF,0XF0,0X1C,0XFF,0XFF,0XFF,0XFF,0XFF,0XF7,0XF8,0X0E,0X30,0X0B,0XFF,0XF0,
0X0C,0X7F,0XFF,0XFF,0XFF,0XFF,0XF7,0XFC,0X07,0X18,0X1F,0XFF,0XFC,0X0F,0X3F,0XFF,
0XFF,0XFF,0XFF,0XF3,0XFE,0X07,0X1C,0X3F,0XFF,0XFE,0X07,0X9F,0XFF,0XFF,0XFF,0XFF,
0XF3,0XFF,0X83,0XCF,0XFF,0XFF,0XFF,0X03,0X8F,0XFF,0XFF,0XFF,0XFF,0XF3,0XFF,0XC3,
0XE7,0XFF,0XFF,0XFF,0X83,0XE7,0XFF,0XFF,0XFF,0XFF,0XF3,0XFF,0XC1,0XF7,0XFF,0XFF,
0XFF,0X81,0XE3,0XFF,0XFF,0XFF,0XFF,0XF3,0XFF,0XE1,0XF3,0XFF,0XFF,0XFF,0XC1,0XF1,
0XFF,0XFF,0XFF,0XFF,0XF3,0XFF,0XE0,0XFB,0XFF,0XFF,0XFF,0XE0,0XF9,0XFF,0XFF,0XFF,
0XFF,0XF3,0XFF,0XF0,0XF9,0XFF,0XFF,0XFF,0XF0,0XFC,0XFF,0XFF,0XFF,0XFF,0XF3,0XFF,
0XF8,0XFD,0XFF,0XFF,0XFF,0XF8,0XFE,0XFF,0XFF,0XFF,0XFF,0XF3,0XFF,0XF8,0X7C,0XFF,
0XFF,0XFF,0XFC,0X7F,0X7F,0XFF,0XFF,0XFF,0XF3,0XFF,0XFC,0X7C,0X7F,0XFF,0XFF,0XFE,
0X7F,0X3F,0XFF,0XFF,0XFF,0XF3,0XFF,0XFC,0X3E,0X7F,0XFF,0XFF,0XFF,0X7F,0XBF,0XFF,
0XFF,0XFF,0XF3,0XFF,0XFE,0X3E,0X3F,0XFF,0XFF,0XFF,0XFF,0XDF,0XFF,0XFF,0XFF,0XF3,
0XFF,0XFE,0X3F,0X3F,0XFF,0XFF,0XFF,0XFF,0XCF,0XFF,0XFF,0XFF,0XF3,0XFF,0XFF,0X3F,
0X3F,0XF0,0XFF,0XFF,0XFF,0XEF,0XFF,0XFF,0XFF,0XF3,0XFF,0XFE,0X3F,0XBF,0XF0,0X03,
0XFF,0XFF,0XC7,0XFF,0XFF,0XFF,0XF3,0XFF,0XFE,0X3F,0XBF,0XE0,0X01,0XFF,0XFF,0XE7,
0XFF,0XFF,0XFF,0XF3,0XFF,0XFF,0X3F,0X9F,0XE0,0X00,0XFF,0XFF,0XE7,0XFF,0XFF,0XFF,
0XF3,0XFF,0XFF,0X3F,0XDF,0XF0,0X00,0X7F,0XFF,0XF3,0XFF,0XFF,0XFF,0XF3,0XFF,0XFF,
0X3F,0XDF,0XFB,0X00,0X7F,0XFF,0XF3,0XFF,0XFF,0XFF,0XF3,0XFF,0XFF,0X3F,0XDF,0XF0,
0X00,0X7F,0XFF,0XFB,0XFF,0XFF,0XFF,0XF3,0XFF,0XFF,0X7F,0XDF,0XC0,0X10,0X3F,0XFF,
0XFB,0XFF,0XFF,0XFF,0XF3,0XFF,0XFF,0XFF,0XDF,0XC0,0X10,0X3F,0XFF,0XFB,0XFF,0XFF,
0XFF,0XF3,0XFF,0XFF,0XFF,0XDF,0XC0,0X10,0X1F,0XFF,0XFB,0XFF,0XFF,0XFF,0XF3,0XFF,
0XFF,0XFF,0XDF,0XC1,0XF8,0X1F,0XFF,0XFB,0XFF,0XFF,0XFF,0XF3,0XFF,0XFF,0XFF,0XDF,
0XC0,0X0C,0X0F,0XFF,0XFB,0XFF,0XFF,0XFF,0XF3,0XFF,0XFF,0XFF,0XDF,0XE0,0X06,0X03,
0XFF,0XF3,0XFF,0XFF,0XFF,0XF3,0XFF,0XFF,0XFF,0XDF,0XE0,0X03,0X00,0X1F,0XF3,0XFF,
0XFF,0XFF,0XF3,0XFF,0XFF,0XFF,0XDF,0XF8,0X01,0XC0,0X03,0XE7,0XFF,0XFF,0XFF,0XF3,
0XFF,0XFF,0XFF,0XDF,0XFC,0X00,0X7F,0X01,0XE7,0XFF,0XFF,0XFF,0XF3,0XFF,0XFF,0XFF,
0XDF,0XFC,0X00,0X3F,0XC0,0XC7,0XFF,0XFF,0XFF,0XF3,0XFF,0XFF,0XFF,0XDF,0XFC,0X00,
0X00,0X00,0XEF,0XFF,0XFF,0XFF,0XF3,0XFF,0XFF,0XFF,0XDF,0XFC,0X00,0X00,0X00,0XDF,
0XFF,0XFF,0XFF,0XF3,0XFF,0XFF,0XFF,0XDF,0XFC,0X00,0X00,0X00,0XDF,0XFF,0XFF,0XFF,
0XF3,0XFF,0XFF,0XFF,0X9F,0XFE,0X00,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XF3,0XFF,0XFF,
0XFF,0X1F,0XFF,0X80,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XF3,0XFF,0XFF,0XFE,0X1F,0XFF,
0XE0,0X00,0X00,0X1F,0XFF,0XFF,0XFF,0XF3,0XFF,0XFF,0XFC,0X1F,0XFF,0XF0,0X00,0X00,
0X1F,0XFF,0XFF,0XFF,0XF3,0XFF,0XFF,0XFF,0X9F,0XFF,0XF0,0X00,0X18,0X1F,0XFF,0XFF,
0XFF,0XF3,0XFF,0XFF,0XFF,0XDF,0XFF,0XF0,0X00,0X30,0X1F,0XFF,0XFF,0XFF,0XF3,0XFF,
0XFF,0XFF,0XDF,0XFF,0XF1,0X83,0XC0,0X3F,0XFF,0XFF,0XFF,0XF3,0XFF,0XFF,0XFE,0XCF,
0XFF,0XE0,0XFF,0X01,0X3F,0XFF,0XFF,0XFF,0XF3,0XFF,0XFF,0X84,0XCF,0XFF,0X00,0X70,
0X01,0X1F,0XFF,0XFF,0XFF,0XF3,0XFF,0XFF,0X06,0X67,0XFE,0X00,0X40,0X02,0X3F,0XFF,
0XFF,0XFF,0XF3,0XFF,0XFE,0X07,0XE7,0XFE,0X00,0X40,0X06,0X3F,0XFF,0XFF,0XFF,0XFB,
0XFF,0XFC,0X03,0XE1,0XFE,0X00,0X40,0X06,0X7F,0XFF,0XFF,0XFF,0XFB,0XFF,0XFC,0X04,
0X60,0XFF,0X00,0X40,0X0C,0XFF,0XFF,0XFF,0XFF,0XFB,0XFF,0XFE,0X18,0X30,0X7F,0X80,
0X00,0X18,0XFF,0XFF,0XFF,0XFF,0XFB,0XFF,0XE0,0X38,0X36,0X3F,0XC0,0X00,0X19,0XFF,
0XFF,0XFF,0XFF,0XFB,0XFF,0XC0,0X20,0X33,0X1F,0XF0,0X00,0X31,0XFF,0XFF,0XFF,0XFF,
0XFB,0XFF,0XC0,0XC8,0X11,0X8F,0XF8,0X00,0X63,0XFF,0XFF,0XFF,0XFF,0XFB,0XFF,0X80,
0XC0,0X39,0X8F,0XFC,0X00,0X63,0XFF,0XFF,0XFF,0XFF,0XFB,0XFF,0XF9,0X80,0X48,0XC7,
0XFC,0X00,0X43,0XFF,0XFF,0XFF,0XFF,0XFB,0XFF,0XBF,0X06,0XC4,0X07,0XFC,0X00,0XC3,
0XFF,0XFF,0XFF,0XFF,0XFB,0XFE,0X03,0X07,0X86,0X07,0XFC,0X0C,0X83,0XFF,0XFF,0XFF,
0XFF,0XFB,0XFE,0X01,0X07,0X86,0X07,0XFC,0X1E,0X83,0XFF,0XFF,0XFF,0XFF,0XFB,0XFC,
0X05,0X07,0X93,0X07,0XFC,0X1D,0X81,0XFF,0XFF,0XFF,0XFF,0XFB,0XFC,0X08,0X0F,0XB1,
0X03,0XFE,0X23,0XE1,0XFF,0XFF,0XFF,0XFF,0XFB,0XFF,0XF8,0XFF,0X99,0X23,0XFF,0XE7,
0X30,0XFF,0XFF,0XFF,0XFF,0XFB,0XFE,0X00,0XFF,0XC0,0X91,0XFF,0X80,0X10,0X7F,0XFF,
0XFF,0XFF,0XFB,0XFC,0X00,0XFF,0XE0,0X98,0XFF,0X00,0X00,0X7F,0XFF,0XFF,0XFF,0XFF,
0XFC,0X00,0XFF,0XE0,0X8C,0X7F,0X00,0X00,0X7F,0XFF,0XFF,0XFF,0XFF,0XFC,0X21,0XFF,
0XF8,0X80,0X7F,0X00,0X00,0X7F,0XFF,0XFF,0XFF,0XFF,0XFC,0X71,0XFF,0XFC,0X80,0X7F,
0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X40,0X3F,0X80,0X00,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X3F,0X80,0X01,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X3F,0XE0,0X01,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XC0,0X7F,0XFC,0X01,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,
0X3F,0XFC,0X01,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF8,0X3F,0XFC,0X01,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X03,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X07,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X9F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,
};

const unsigned char BitmapWaveshare_red[] PROGMEM = {
/* 0X00,0X01,0X68,0X00,0XD4,0X00, */
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X7F,
0XFE,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF8,0X3F,0XFC,0X3F,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X1F,0XF0,0X3F,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X0F,0XC0,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0X80,0X47,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,
0X02,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X83,0X86,0X78,0X3F,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X82,0X0C,0XE0,0X0F,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X0C,0X80,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0X80,0X05,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XC6,0X04,0X00,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X04,0X00,
0X01,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X04,0X60,0X01,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X06,0X60,0X01,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFC,0X0E,0X00,0X01,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XE2,0X20,0X01,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,
0X10,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X80,0X00,0X07,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X80,0X18,0X07,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X80,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XF0,0XC0,0X80,0X3C,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,
0XC0,0X7F,0XF0,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X60,0X40,0X00,
0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X38,0X20,0X00,0X0F,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X1C,0X18,0X00,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFC,0X03,0X0C,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0X06,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X01,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0XC9,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0XCF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X47,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XE0,0X07,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,
0X07,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X07,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF9,0XCF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X3F,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X3F,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFE,0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,
0X07,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X07,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X4E,0X07,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X01,0X07,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFE,0X01,0X07,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,
0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1C,0X01,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFE,0X68,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XF0,0XC4,0X00,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF1,0X06,0X00,
0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0X03,0X00,0X3F,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE2,0X01,0X80,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XC1,0XC0,0X80,0X07,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XC0,0X70,0XC0,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X38,
0X00,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X0C,0X01,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X1F,0XFF,0X8F,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X70,0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0X81,0X00,0X00,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC1,
0X00,0X00,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X0F,0XC0,0X7F,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X0F,0XC0,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X00,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFA,0X07,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFE,0X07,0X07,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X08,0X03,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X03,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X01,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XF8,0X01,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,
0X07,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,
};
#endif

