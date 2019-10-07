#ifndef __CONTEXT_TASK__
#define __CONTEXT_TASK__

#include "Task.h"
#include "Context.h"

namespace Tusk {
    class ContextTask : public Task {
    public:
        Context* getContext();
        void setContext(Context* context);
    private:
        Context* context;
    };
}

#endif
