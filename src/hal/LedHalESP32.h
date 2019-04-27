#ifdef ESP32

#include "LedHal.h"
#include "esp32-hal-ledc.h"

#ifndef LEDHALESP32_H
#define LEDHALESP32_H

class LedHalESP32 : public LedHal {
private:
    static int nextChannel;
    int channel;
    int pin;
protected:
    void init();
    void setDuty(uint32_t duty);
public:
    LedHalESP32(int led, int channel = -1);
};

#endif
#endif
