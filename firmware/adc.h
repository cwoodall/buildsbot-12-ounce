#ifndef ADC_H
#define ADC_H

#include <stdint.h>
#include <avr/io.h>

void initADC();
uint16_t readADC(uint8_t ADCchannel);

class ADCchannel
{
    uint8_t pin;
    volatile uint8_t * port;
    uint16_t value;
public:
    ADCchannel(uint8_t, volatile uint8_t *);
    uint16_t getValue();
    void update();
};


#endif
