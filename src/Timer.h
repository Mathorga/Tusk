/*
**************************************************************************
Timer.h

TODO

Copyright (C) 2019 Luka Micheletti
**************************************************************************
*/

#ifndef __TIMER__
#define __TIMER__

namespace Tusk {
    class Timer {
    public:
        Timer();
        void setupFreq(int freq);
        void setupPeriod(int period);
        void waitForNextTick();
    };
}

#endif
