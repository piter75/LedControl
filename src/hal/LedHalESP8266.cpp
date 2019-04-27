#ifdef ESP8266

#include "Arduino.h"
#include "LedHalESP8266.h"

LedHalESP8266::LedHalESP8266(int pin) {
    this->pin = pin;
};

void LedHalESP8266::init() {
    pinMode(pin, OUTPUT);
    analogWriteFreq(5000);
}

void LedHalESP8266::setDuty(uint32_t duty) {
    Serial.println("Setting duty for led for ESP8266");
    analogWrite(pin, duty * 4);
};

#endif
