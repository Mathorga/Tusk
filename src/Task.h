/*
********************************************************************************
Task.h

This class defines the default interface for a Task object.
Tusk compliance is achieved inheriting from Task.

Copyright (C) 2019 Luka Micheletti
********************************************************************************
*/

#ifndef __TASK__
#define __TASK__

namespace Tusk {
    class Task {
    public:
        // Initializes all variables needed by the task.
        // The init method can be as long and complex as needed, since it is run just once.
        virtual void init(int period) {
            this->period = period;
            this->elapsedTime = 0;
        }

        // Executes an atomic action needed by the task to do its job.
        // The action needs to be as simple and short as possible, since it is executed continuously.
        virtual void tick() = 0;

        bool update(int basePeriod) {
            this->elapsedTime += basePeriod;
            if (this->elapsedTime >= this->period){
                this->elapsedTime = 0;
                return true;
            } else {
                return false;
            }
        }

        int getPeriod() {
            return this->period;
        }
    private:
        int period;
        int elapsedTime;
    };
}

#endif
