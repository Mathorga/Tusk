/*
********************************************************************************
Timer.h

TODO

Copyright (C) 2019 Luka Micheletti
********************************************************************************
*/

#ifndef __TIMER__
#define __TIMER__

#include "Arduino.h"

namespace Tusk {
    class Timer {
    public:
        Timer();
        void setupFrequency(int frequency);
        void setupPeriod(int period);
        void waitTick();
    };
}

#endif
