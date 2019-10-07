#ifndef __CONTEXT__
#define __CONTEXT__

#include "Task.h"

namespace Tusk {
    class Context {
    public:
        static const int MAX_TASKS_NUM;

        Context();
        bool addTask(Task* task);
        Task* getTaskAt(int index);
        Task** getTasks();
    private:
        //TODO Don't use Task, use ProducerTask or something like this.
        Task** tasks;
        int tasksNum;
    };
}

#endif
