#include "Consumer.h"

namespace Tusk {
    Context* Consumer::getContext() {
        return this->context;
    }

    void Consumer::setContext(Context* context) {
        this->context = context;
    }
}
