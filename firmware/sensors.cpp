#include <stdint.h>
#include "adc.h"
#include "sensors.h"

uint8_t LineSensor::isThreshold() 
{
    return (getValue() >= threshold)?1:0;
}
