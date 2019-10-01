#include "Scheduler.h"

namespace Tusk {
    const int Scheduler::MAX_TASKS_NUM = 10;

    void Scheduler::init(int basePeriod) {
        this->basePeriod = basePeriod;
        this->timer.setupPeriod(basePeriod);
        this->tasksNum = 0;
        this->tasks = (Task**) malloc(MAX_TASKS_NUM * sizeof(Task*));
    }

    bool Scheduler::addTask(Task* task) {
        bool result = true;

        // Check if the new task does not exceed the maximum task number.
        if (this->tasksNum < MAX_TASKS_NUM - 1) {
            // Check if task's period is compatible with base period.
            // Base period need to be the greatest common divisor of all the tasks it manages.
            //TODO Dynamically adjust the base period according to all the added tasks.
            if (task->getPeriod % this->basePeriod == 0) {
                this->tasks[this->tasksNum] = task;
                this->tasksNum++;
            } else {
                result = false;
            }
        } else {
            result = false;
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
