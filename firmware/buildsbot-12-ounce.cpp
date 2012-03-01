/**
 * Project: BUILDSbot 12 Ounce
 * Version: 01
 * Creator(s): Christopher Woodall
 * License: MIT License
 * 
 * 
 */
#define F_CPU 16000000 /* 16MHz Internal Oscillator */
#define BAUDRATE 9600
#define MYUBRR (F_CPU / 16 / BAUDRATE) - 1

#include <avr/io.h>
#include "pins.h"
#include "motor.h"
#include "adc.h"
#include "sensors.h"

// void initPWM() sets up the TIMERS and scaling for PWM on pins 11 and 9
void initPWM();

int main(void) 
{
    DDRB = 0x3F;
    initPWM();
    initADC();
    
    Motor leftMotor( P11, &PORTB, (volatile uint16_t *) &OCR2A, P8, &PORTB, 
                     P10, &PORTB);
    leftMotor.setSpeed(1023,HALT);
    
    Motor rightMotor( P9, &PORTB, &OCR1A, P12, &PORTB, P13, &PORTB);
    rightMotor.setSpeed(1023, HALT);
    
    LineSensor lSensor( A2, &PORTC, 100);
    LineSensor mSensor( A1, &PORTC, 100);
    LineSensor rSensor( A0, &PORTC, 100);
    
    int a = 0;
    while (1) {
        lSensor.update();
        mSensor.update();
        rSensor.update();
        
        if ((lSensor.getValue() < 100) && (rSensor.getValue() < 100) && 
            (mSensor.getValue() < 100)) {
            if (a == 1) {
                rightMotor.setSpeed(1023,FORWARD);
                leftMotor.setSpeed(500, FORWARD);
            } else if (a == 2) {
                rightMotor.setSpeed(500, BACKWARD);
                leftMotor.setSpeed(1023, FORWARD);
            } else {
                leftMotor.setSpeed(500, FORWARD);
                rightMotor.setSpeed(500, FORWARD);
            }
        } else if ((lSensor.getValue() > 100) && (rSensor.getValue() > 100) && 
                   (mSensor.getValue() < 100)) {
            rightMotor.setSpeed(1023, FORWARD);
            leftMotor.setSpeed(1023, BACKWARD);
        } else if ((mSensor.getValue() > 100) && (lSensor.getValue() < 100) && 
                   (rSensor.getValue() < 100)) {
            rightMotor.setSpeed(1023, FORWARD);
            leftMotor.setSpeed(1023, FORWARD);
        } else if (rSensor.getValue() > 100) {
            rightMotor.setSpeed(1023, FORWARD);
            leftMotor.setSpeed(500, HALT);
            a = 1;
        } else if (lSensor.getValue() > 100) {
            rightMotor.setSpeed(500, HALT);
            leftMotor.setSpeed(1023, FORWARD);
            a = 2;
        } 
    }
    return 0;
}

void initPWM()
{
    TCCR2A |= (1 << COM2A1);
    // set none-inverting mode
    TCCR2A |= (1 << WGM21) | (1 << WGM20);
    // set fast PWM Mode
    
    TCCR1A |= (1 << COM2A1);
    // set none-inverting mode
    TCCR1A |= (1 << WGM21) | (1 << WGM20);
    // set fast PWM Mode
    
    // set prescaler to 8 and starts PWM
    TCCR2B |= (1 << CS21);
    TCCR1B |= (1<<CS21);
}
