#ifndef __CONTEXT__
#define __CONTEXT__

#include "Producer.h"
#include "Arduino.h"

namespace Tusk {
    class Context {
    public:
        static const int MAX_PRODUCERS_NUM;

        Context();
        bool addProducer(Producer* task);
        Producer* getProducerAt(int index);
        Producer** getProducers();
    private:
        Producer** producers;
        int producersNum;
    };
}

#endif
