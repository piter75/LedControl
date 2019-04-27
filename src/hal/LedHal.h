#include "stdint.h"

#ifndef LEDHAL_H
#define LEDHAL_H

class LedHal {
public:
    virtual ~LedHal();
    virtual void init() = 0;
    virtual void setDuty(uint32_t duty) = 0;
};

#endif
