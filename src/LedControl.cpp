#include "Arduino.h"
#include "stdint.h"
#include "LedControl.h"

LedControl::LedControl(int pin, bool reversed) {
    this->pin = pin;
    this->reversed = reversed;

    #ifdef ESP32
      this->ledHal = new LedHalESP32(pin);
    #endif
    #ifdef ESP8266
      this->ledHal = new LedHalESP8266(pin);
    #endif

    selfCreatedHal = true;
};

LedControl::LedControl(LedHal *hal) {
  this->ledHal = hal;
}

LedControl::~LedControl() {
  if (selfCreatedHal) {
    delete ledHal;
  }
};

void LedControl::init() {
  ledHal->init();
}

void LedControl::on(uint32_t duty) {
    ledHal->setDuty(calculateDuty(duty));
};

void LedControl::off() {
    ledHal->setDuty(calculateDuty(fullyOffDuty));
};

void LedControl::blink(uint32_t peakDuty, uint32_t time, uint8_t step) {
  uint32_t singleStepTime = time / 2 / (peakDuty / step);

  for(int32_t duty = fullyOffDuty; duty < peakDuty; duty += step) {
    ledHal->setDuty(calculateDuty(duty));
    delay(singleStepTime);
  }

  for(int32_t duty = peakDuty - 1; duty >= fullyOffDuty; duty -= step) {
    ledHal->setDuty(calculateDuty(duty));
    delay(singleStepTime);
  }

  this->off();
}

uint32_t LedControl::calculateDuty(uint32_t duty) {
  return this->reversed ? fullyOnDuty - duty : duty;
}
