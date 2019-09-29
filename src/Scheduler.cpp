#include "Scheduler.h"

namespace Tusk {
    void Scheduler::init(int basePeriod) {
        this->basePeriod = basePeriod;
        this->timer.setupPeriod(basePeriod);
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
        this->timer.waitTick();
        for (int i = 0; i < this->tasksNum; i++) {
            if (this->tasks[i]->update(this->basePeriod)) {
                this->tasks[i]->tick();
            }
        }
    }
}
