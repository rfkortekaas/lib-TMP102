#ifndef __TMP102_h
#define __TMP102_h

#include <Arduino.h>
#include <TwoWireDevice.h>

#define TMP102_ADDRESS_DEFAULT     (0x48)

#define TMP102_TEMPERATUR_REG      (0x00)

class TMP102: public TwoWireDevice {
    public:
        TMP102(TwoWire& wire, const uint8_t addr = TMP102_ADDRESS_DEFAULT) : TwoWireDevice(wire, addr) {};
        TMP102(const uint8_t addr = TMP102_ADDRESS_DEFAULT) : TwoWireDevice(addr) {};

        bool begin();

        float readTemperature(void);
    
    protected:

    private:
        TMP102(const TMP102&);
        TMP102& operator=(const TMP102&);
};


#endif // __TMP102_h