#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "Task.h"
#include "Timer.h"

#define MAX_TASKS 10

namespace Tusk {
    class Scheduler {
    public:
        void init(int period);
        virtual bool addTask(Task* task);
        virtual void schedule();

    private:
        static bool ready;
        int period;
        int nTasks;
        Task* taskList[MAX_TASKS];
        Timer* timer;
    };
}

#endif
