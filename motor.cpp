#include "motor.h"

Motor::Motor( uint8_t en, volatile uint8_t * en_p, volatile uint16_t * t,
              uint8_t a, volatile uint8_t * a_p, uint8_t b, volatile uint8_t * b_p )
{
    en_pin = en;
    en_port = en_p;
    timer = t;

    ina_pin = a;
    ina_port = a_p;

    inb_pin = b;
    inb_port = b_p;

    speed = 0;
    direction = FORWARD;
}

void Motor::setSpeed( uint16_t sp)
{
    speed = sp;
    *timer = speed;
}

void Motor::setSpeed( uint16_t sp, enum Direction dir )
{
    speed = sp;
    direction = dir;
    
    *timer = speed;
    
    switch (direction) {
    case FORWARD:
        // Turn off ina_pin
        *ina_port &= ~(1<<ina_pin);
        // Turn on inb_pin
        *ina_port |= (1<<inb_pin);        
        break;
    case BACKWARD:
        // Turn off inb_pin
        *inb_port &= ~(1<<inb_pin);
        // Turn on ina_pin
        *ina_port |= (1<<ina_pin);        
        break;
    default:
        // In an undefined case halt the motors.
        // Turn both pins on to halt
        *inb_port |= (1<<inb_pin);
        *ina_port |= (1<<ina_pin);
        break;
    }
}
