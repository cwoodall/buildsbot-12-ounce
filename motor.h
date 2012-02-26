#ifndef MOTOR
#define MOTOR

#include <stdint.h>

// enumerate the directions for easy access
enum Direction {
    HALT=0,
    FORWARD,
    BACKWARD
};

class Motor
{
    uint8_t en_pin;
    volatile uint8_t * en_port;
    volatile uint16_t * timer;

    uint8_t ina_pin;
    volatile uint8_t * ina_port;
    
    uint8_t inb_pin;
    volatile uint8_t * inb_port;

    uint16_t speed;
    enum Direction direction;
public:
    Motor(uint8_t, volatile uint8_t *, volatile uint16_t *, uint8_t, 
          volatile uint8_t *, uint8_t, volatile uint8_t *);
    void setSpeed(uint16_t, enum Direction);
    void setSpeed(uint16_t);
};

#endif
