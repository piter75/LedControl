#ifdef ESP32

#include "Arduino.h"
#include "LedHalESP32.h"

int LedHalESP32::nextChannel = 0;

LedHalESP32::LedHalESP32(int pin, int channel) {
    this->pin = pin;
    if (channel == -1) {
        this->channel = this->nextChannel++;
    } else {
        this->channel = channel;
    }
};

void LedHalESP32::init() {
    ledcAttachPin(pin, channel);
    ledcSetup(channel, 5000, 8);
}

void LedHalESP32::setDuty(uint32_t duty) {
    ledcWrite(this->channel, duty);
};

#endif
