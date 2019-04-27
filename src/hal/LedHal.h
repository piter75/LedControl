#include "stdint.h"

#ifndef LEDHAL_H
#define LEDHAL_H

class LedHal {
public:
    virtual ~LedHal() {};
    virtual void init();
    virtual void setDuty(uint32_t duty);
};

#endif
