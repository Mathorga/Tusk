#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "Task.h"
#include "Timer.h"

namespace Tusk {
    class Scheduler {
    public:
        // Maximum number of tasks that can be managed by the scheduler.
        // In order to avoid
        static const int MAX_TASKS_NUM;

        void init(int basePeriod);
        virtual bool addTask(Task* task);
        virtual void schedule();

    private:
        static bool ready;
        int basePeriod;
        int tasksNum;
        Task** tasks;
        Timer timer;
    };
}

#endif
