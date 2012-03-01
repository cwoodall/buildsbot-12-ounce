#ifndef SENSORS_H
#define SENSORS_H

class LineSensor : public ADCchannel
{
public:
    uint16_t threshold;
    LineSensor(uint8_t p, volatile uint8_t * po, uint16_t thresh) 
        : ADCchannel(p, po) { threshold = thresh; };
    uint8_t isThreshold();
};

#endif
