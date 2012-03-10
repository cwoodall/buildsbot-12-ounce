/**
 * Project: BUILDSbot 12 Ounce
 * Version: 01
 * Creator(s): Christopher Woodall
 * License: MIT License
 * 
 * 
 */
#define F_CPU 16000000 /* 16MHz Internal Oscillator */

#include <avr/io.h>
#include "pins.h"
#include "motor.h"
#include "adc.h"
#include "sensors.h"

// void initPWM() sets up the TIMERS and scaling for PWM on pins 11 and 9
void initPWM();

int main( void ) 
{
    // Set outputs for Arduino Pins 8-11 to be outputs
    DDRB = 0x3F;
    // Initialize Pulse Width Modulator and ADC.
    // Necissary inorder to use motors and ADCs.
    initPWM(); // May need to customize your initPWM() method depending on uC
    initADC();
    
    // Initialize Motors and set them to HALT
    Motor leftMotor( P11, &PORTB, (volatile uint16_t *) &OCR2A, P8, &PORTB, 
                     P10, &PORTB );
    leftMotor.setSpeed( 1023, HALT );
    
    Motor rightMotor( P9, &PORTB, &OCR1A, P12, &PORTB, P13, &PORTB);
    rightMotor.setSpeed( 1023, HALT );
    
    // Initialize Line Sensors with threshold set to 100
    LineSensor lSensor( A2, &PORTC, 100 );
    LineSensor mSensor( A1, &PORTC, 100 );
    LineSensor rSensor( A0, &PORTC, 100 );
    
    int a = 0;
    // Enter the Super Loop
    while (1) {
        lSensor.update();
        mSensor.update();
        rSensor.update();
        
        // Insert Line Sensor logic here
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
