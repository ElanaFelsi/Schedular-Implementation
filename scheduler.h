#ifndef SCHEDULER_ELANAFELSI_SCHEDULER_H
#define SCHEDULER_ELANAFELSI_SCHEDULER_H

#include "task.h"
#include <queue>

class Scheduler
{
public:
    explicit Scheduler(unsigned long tq);

    void addTask(Task& task);

    void runTask();

private:
    std::queue<Task*> m_tasks;
    unsigned long m_timeQuantum; /* in milliseconds */
};

inline void Scheduler::addTask(Task &task) {
    m_tasks.push(&task);
}

inline Scheduler::Scheduler(unsigned long tq):m_timeQuantum(tq){}



#endif //SCHEDULER_ELANAFELSI_SCHEDULER_H
