#include <Arduino.h>
#include <TwoWireDevice.h>

#include "TMP102.h"

bool TMP102::begin() {
    static bool init = TwoWireDevice::begin();

    // Test read
    read8();

    return (init);
}

float TMP102::readTemperature() {
    uint8_t registerByte[2];
    int16_t digitalTemperature;
    readreg(TMP102_TEMPERATUR_REG, registerByte, 2);
    
    digitalTemperature = ((registerByte[0]) << 4) | (registerByte[1] >> 4);
    if (digitalTemperature > 0x7FF) {
        digitalTemperature |= 0xF000;
    }


    return( (float) digitalTemperature * 0.0625);
}