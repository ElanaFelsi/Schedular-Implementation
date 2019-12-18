#ifndef SCHEDULER_ELANAFELSI_SCHEDULER_H
#define SCHEDULER_ELANAFELSI_SCHEDULER_H

#include "task.h"
#include <queue>
#include <unistd.h>

#define CREATE_PAIR(task) make_pair(Time((task)->getNextRunPeriod()), (task))

using std::make_pair;
using std::pair;

typedef  pair<Time, Task*> TimedTask;
class Scheduler
{
public:
    void addTask(Task *task);
    void run();

private:
    bool shouldRun();
    void executeNextTask();
    void waitUntilNext(unsigned long next);
    bool timeNotReachedYet(Time next);

    std::queue<TimedTask> m_tasks;
    Time m_timer;
};

inline void Scheduler::addTask(Task *task) {
    m_tasks.push(CREATE_PAIR(task));
}

inline void Scheduler::run() {
    unsigned long timeLeft = 0;

    while(shouldRun())
    {
        waitUntilNext(timeLeft);
        executeNextTask();
    }

}

inline bool Scheduler::shouldRun() {
    return !m_tasks.empty();
}

inline void Scheduler::executeNextTask() {
    Task *task = m_tasks.front().second;
    m_tasks.pop();

    task->run();
    unsigned long nextTime = task->getNextRunPeriod();

    if(nextTime)
    {
        m_tasks.push(make_pair(nextTime, task));
    }
    else
    {
        cout << "Task ended " << endl;
    }

}

void Scheduler::waitUntilNext(unsigned long next) {
    Time nextTime = m_tasks.front().first;

    if (timeNotReachedYet(nextTime)) {
        unsigned long sleepingTime = nextTime - m_timer;

        cout << "---Scheduler: next run in " << nextTime.GetTimeInMill() << "ms" << endl;
        usleep(sleepingTime * 1000);
    }
}
inline bool Scheduler::timeNotReachedYet(Time next) {
    m_timer.now();
    return (m_timer < next);
}


#endif //SCHEDULER_ELANAFELSI_SCHEDULER_H
