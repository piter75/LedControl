#include <Arduino.h>

#include "LedControl.h"

LedControl builtInLed(LED_BUILTIN, false);

void setup() {
    builtInLed.init();
}

void loop() {
    builtInLed.blink(127, 50, 8);
    delay(2000);
}
