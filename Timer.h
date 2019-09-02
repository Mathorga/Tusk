#ifndef __TIMER_RICCI__
#define __TIMER_RICCI__

class Timer {
  public:
    Timer();
    void setupFreq(int freq);
    void setupPeriod(int period);
    void waitForNextTick();
};

#endif
