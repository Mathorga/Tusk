#include "Scheduler.h"

namespace Tusk {
    void Scheduler::init(int period) {
        this->period = period;
        this->timer->setupPeriod(period);
        this->tasksNum = 0;
    }

    bool Scheduler::addTask(Task* task) {
        if (this->tasksNum < MAX_TASKS - 1) {
            this->tasks[this->tasksNum] = task;
            this->tasksNum++;
            return true;
        } else {
            return false; 
        }
    }

    void Scheduler::schedule() {
        this->timer->waitForNextTick();
        for (int i = 0; i < this->tasksNum; i++) {
            this->tasks[i]->tick();
        }
    }
}
