#include "Task.h"

namespace Tusk {
    void Task::init(int period) {
        this->period = period;
        this->elapsedTime = 0;
    }

    bool Task::update(int basePeriod) {
        this->elapsedTime += basePeriod;
        if (this->elapsedTime >= this->period){
            this->elapsedTime = 0;
            return true;
        } else {
            return false;
        }
    }

    int Task::getPeriod() {
        return this->period;
    }
}
