#ifndef PINS_H
#define PINS_H

#include <avr/io.h>

// Give us the Arduino pin bindings. This is dirty, but lets us easily access 
// the appropriate pins easily.
//
// To use properly you still need to know what the appropriate port is.
#define P13 PB5
#define P12 PB4
#define P11 PB3
#define P10 PB2
#define P9  PB1
#define P8  PB0
#define P7  PD7
#define P6  PD6
#define P5  PD5
#define P4  PD4
#define P3  PD3
#define P2  PD2
#define P1  PD1
#define P0  PD0
#define A0  PC0
#define A1  PC1
#define A2  PC2
#define A3  PC3
#define A4  PC4
#define A5  PC5

#endif
