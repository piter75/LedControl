#include "stdint.h"
#include "hal/LedHal.h"

#ifndef LedControl_h
#define LedControl_h

#ifdef ESP32
    #include "hal/LedHalESP32.h"
#endif

#ifdef ESP8266
    #include "hal/LedHalESP8266.h"
#endif

const uint8_t fullyOffDuty = 0;
const uint32_t fullyOnDuty = 256;

class LedControl {
private:
    LedHal *ledHal;
    int pin;
    bool reversed;
    bool selfCreatedHal = false;
public:
    LedControl(int pin, bool reversed);
    LedControl(LedHal *hal);
    ~LedControl();
    void init();
    void on(unsigned int duty = fullyOnDuty);
    void off();
    void blink(uint32_t maxDuty, uint32_t time, uint8_t step);
    uint32_t calculateDuty(uint32_t duty);
};

#endif
