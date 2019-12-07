#include "scheduler.h"

void Scheduler::runTask()
{
    while(!m_tasks.empty())
    {
        Task *task;
        task = m_tasks.front();

        task->run();
        m_tasks.pop();

        if(task->m_runTime > m_timeQuantum)
        {
            task->m_runTime -= m_timeQuantum;
            m_tasks.push(task);
        }

    }
}

