#include "LedHal.h"

#ifndef LEDHALESP8266_H
#define LEDHALESP8266_H

class LedHalESP8266 : public LedHal {
private:
    int pin;
protected:
    void init();
    void setDuty(uint32_t duty);
public:
    LedHalESP8266(int led);
};

#endif
