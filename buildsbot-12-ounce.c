/**
 * Project: BUILDSbot 12 Ounce
 * Version: 01
 * Creator(s): Christopher Woodall
 * License: MIT License
 * 
 */
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define F_CPU 16000000 /* 16MHz Internal Oscillator */
#define BAUDRATE 9600
#define MYUBRR (F_CPU / 16 / BAUDRATE) - 1

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

typedef enum {
    TRUE=0,
    FALSE
} boolean;

enum Direction {
    FORWARD=0,
    BACKWARD
};

typedef struct {
    uint8_t en_pin;
    uint8_t ina_pin;
    uint8_t inb_pin;
    uint8_t port;

    uint16_t speed;
    enum Direction direction;
} Motor;

typedef struct {
    uint8_t  pin;
    uint16_t value;
    //    boolean  black;
} LineSensor;

void updateLineSensor( LineSensor * sensor );
void updateMotor( Motor motor );
void testBench( Motor leftMotor, Motor rightMotor );

void initPWM();
void initADC();
uint16_t readADC(uint8_t ADCchannel);

int main(void) 
{
    DDRB = 0x3F;
    DDRC = 0;
    initPWM();
    initADC();
    Motor leftMotor;
    leftMotor.en_pin = P11;
    leftMotor.ina_pin = P8;
    leftMotor.inb_pin = P10;
    leftMotor.speed = 0;
    leftMotor.direction = FORWARD;
    updateMotor(leftMotor);


    Motor rightMotor;    
    rightMotor.en_pin = P9;
    rightMotor.inb_pin = P13;
    rightMotor.ina_pin = P12;
    rightMotor.speed = 0;
    rightMotor.direction = FORWARD;
    updateMotor(rightMotor);


    //    testBench(leftMotor, rightMotor);
    LineSensor lSensor;
    lSensor.pin = A2;

    LineSensor mSensor;
    mSensor.pin = A1;
 
    LineSensor rSensor;
    rSensor.pin = A0;


    int a = 0;
    while (1) {
        updateLineSensor(&lSensor);
        updateLineSensor(&mSensor); 
        updateLineSensor(&rSensor);


        if ((lSensor.value < 100) && (rSensor.value < 100) && (mSensor.value < 100)) {
            if (a == 1) {
                rightMotor.direction = FORWARD;
                leftMotor.direction = FORWARD;
                leftMotor.speed = 800;
                rightMotor.speed = 1023;
                updateMotor(rightMotor);
                updateMotor(leftMotor);
            } else if (a == 2) {
                rightMotor.direction = FORWARD;
                leftMotor.direction = FORWARD;
                leftMotor.speed = 1023;
                rightMotor.speed = 800;
                updateMotor(rightMotor);
                updateMotor(leftMotor);
            } else {
                rightMotor.direction = FORWARD;
                leftMotor.direction = FORWARD;
                leftMotor.speed = 500;
                rightMotor.speed = 500;
                updateMotor(rightMotor);
                updateMotor(leftMotor);
            }
        } else if ((lSensor.value > 100) && (rSensor.value > 100) && (mSensor.value < 100)) {
            rightMotor.direction = FORWARD;
            leftMotor.direction = BACKWARD;
            leftMotor.speed = 1023;
            rightMotor.speed = 1023;
            updateMotor(rightMotor);
            updateMotor(leftMotor);
        } else if ((mSensor.value > 100) && (lSensor.value < 100) && (rSensor.value < 100)) {
            rightMotor.speed = 1023;
            rightMotor.direction = FORWARD;
            updateMotor(rightMotor);
            leftMotor.speed = 1023;
            leftMotor.direction = FORWARD;
            updateMotor(leftMotor);
        } else if (rSensor.value > 100) {
            rightMotor.speed = 1023;
            rightMotor.direction = FORWARD;
            updateMotor(rightMotor);
            a = 1;
            leftMotor.speed = 0;
            leftMotor.direction = FORWARD;
            updateMotor(leftMotor);
        } else if (lSensor.value > 100) {
            leftMotor.speed = 1023;
            leftMotor.direction = FORWARD;
            updateMotor(leftMotor);
            
            rightMotor.speed = 0;
            rightMotor.direction = FORWARD;
            updateMotor(rightMotor);
            a = 2;
        } else {
          
        }

        
        rightMotor.direction = FORWARD;
        leftMotor.direction = FORWARD;    
        
    }
    
    return 0;
}

void updateMotor( Motor motor ) 
{
    if (motor.en_pin == P11) {
        OCR2A = motor.speed;
    }
    if (motor.en_pin == P9) {
        OCR1A = motor.speed;
    }
    
    if (motor.direction == FORWARD) {
        PORTB &= ~(1<<motor.ina_pin);
        PORTB |= (1<<motor.inb_pin);
    } else {
        PORTB &= ~(1<<motor.inb_pin);
        PORTB |= (1<<motor.ina_pin);
    }

}

void updateLineSensor( LineSensor * sensor ) 
{
    (*sensor).value = readADC((*sensor).pin); 
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

void initADC()
{
    // Select Vref = AVcc
    ADMUX |= (1<<REFS0);
    //set prescaler to 127 and enable the ADC
    ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN);
}

uint16_t readADC(uint8_t ADCchannel)
{
    // select ADC channel with safety mask
    ADMUX = (ADMUX & 0xF0) | (ADCchannel & 0x0F);
    // single conversion mode
    ADCSRA |= (1<<ADSC);
    // wait until ADC conversion is complete
    while( ADCSRA & (1<<ADSC) );
    return ADC;
}

void testBench(Motor leftMotor, Motor rightMotor) 
{
        rightMotor.speed = 1023;
        leftMotor.speed = 1023;
        leftMotor.direction = FORWARD;
        rightMotor.direction = BACKWARD;
        
        updateMotor(leftMotor);
        updateMotor(rightMotor);

        _delay_ms(1000);

        rightMotor.speed = 1023;
        leftMotor.speed = 1023;
        leftMotor.direction = FORWARD;
        rightMotor.direction = FORWARD;
        
        updateMotor(leftMotor);
        updateMotor(rightMotor);

        _delay_ms(1000);

        rightMotor.speed = 1023;
        leftMotor.speed = 1023;
        leftMotor.direction = BACKWARD;
        rightMotor.direction = FORWARD;
        
        updateMotor(leftMotor);
        updateMotor(rightMotor);

        _delay_ms(1000);

        rightMotor.speed = 1023;
        leftMotor.speed = 1023;
        leftMotor.direction = BACKWARD;
        rightMotor.direction = BACKWARD;
        
        updateMotor(leftMotor);
        updateMotor(rightMotor);
        
        _delay_ms(2000);
        rightMotor.speed = 0;
        leftMotor.speed = 0;
        updateMotor(leftMotor);
        updateMotor(rightMotor);
}
