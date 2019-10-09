/*
********************************************************************************
Consumer.h

This class defines the default interface for a Task object that can handle a
context.

Copyright (C) 2019 Luka Micheletti
********************************************************************************
*/

#ifndef __CONSUMER__
#define __CONSUMER__

#include "Task.h"
#include "Context.h"

namespace Tusk {
    class Consumer : public Task {
    public:
        Context* getContext();
        void setContext(Context* context);
    protected:
        Context* context;
    };
}

#endif
