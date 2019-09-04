#include "Scheduler.h"

void Scheduler::init(int period) {
  this->period = period;
  this->timer->setupPeriod(period);
  this->nTasks = 0;
}

bool Scheduler::addTask(Task* task) {
  if (nTasks < MAX_TASKS - 1){
    taskList[nTasks] = task;
    nTasks++;
    return true;
  } else {
    return false; 
  }
}
  
void Scheduler::schedule() {
  timer->waitForNextTick();
  for (int i = 0; i < nTasks; i++) {
    taskList[i]->tick();
  }
}

