#include "Context.h"

namespace Tusk {
    const int Context::MAX_PRODUCERS_NUM = 10;

    Context::Context() {
        this->producers = (Producer**) malloc(MAX_PRODUCERS_NUM * sizeof(Producer*));
    }

    bool Context::addProducer(Producer* task) {
        bool result = false;

        // Check if the new task does not exceed the maximum producers number.
        if (this->producersNum < MAX_PRODUCERS_NUM - 1) {
            this->producers[this->producersNum] = task;
            this->producersNum++;
            result = true;
        }

        return result;
    }

    Producer* Context::getProducerAt(int index) {
        // Producer* result = nullptr;
        //
        // if (index < this->producersNum) {
        //     result = this->producers[index];
        // }
        //
        // return result;

        return index < this->producersNum ? this->producers[index] : nullptr;
    }

    Producer** Context::getProducers() {
        return this->producers;
    }
}
