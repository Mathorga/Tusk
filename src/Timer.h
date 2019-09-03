#ifndef __TIMER__
#define __TIMER__

class Timer {
  public:
    Timer();
    void setupFreq(int freq);
    void setupPeriod(int period);
    void waitForNextTick();
};

#endif
