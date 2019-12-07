#ifndef SCHEDULER_ELANAFELSI_TASK_H
#define SCHEDULER_ELANAFELSI_TASK_H


#include <iostream>
#include "time.h"

struct ITask
{
    virtual void run() = 0;
    virtual unsigned long getNextRunPeriod() = 0; // in milliseconds
};

struct Task : ITask
{
    explicit Task(Time rt);

    virtual void run(){ std::cout << "Task " << m_taskId << " | rt left: " << m_runTime << std::endl; }

    virtual unsigned long getNextRunPeriod();

    Time m_runTime;

    static int ID;
    int m_taskId;

};

inline int Task::ID = 0;

inline unsigned long Task::getNextRunPeriod()
{
    return 0;
}

inline Task::Task(Time rt): m_runTime(rt), m_taskId(ID++){}


#endif //SCHEDULER_ELANAFELSI_TASK_H
