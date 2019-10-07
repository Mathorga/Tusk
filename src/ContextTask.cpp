#include "ContextTask.h"

namespace Tusk {
    Context* ContextTask::getContext() {
        return this->context;
    }

    void ContextTask::setContext(Context* context) {
        this->context = context;
    }
}
