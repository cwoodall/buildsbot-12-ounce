#include <avr/io.h>
#include "adc.h"


void initADC()
{
    // Select Vref = AVcc
    ADMUX |= (1<<REFS0);
    //set prescaler to 127 and enable the ADCo
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

ADCchannel::ADCchannel(uint8_t p, volatile uint8_t * po)
{
    pin = p;
    port = po;
}

void ADCchannel::update()
{
    value = readADC(pin);
}

uint16_t ADCchannel::getValue() 
{
    return value;
}

