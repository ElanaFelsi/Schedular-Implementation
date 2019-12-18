#ifndef SCHEDULER_ELANAFELSI_TASK_H
#define SCHEDULER_ELANAFELSI_TASK_H

#include <iostream>
#include "time.h"

using std::cout;
using std::endl;

struct ITask
{
    virtual void run() = 0;
    virtual unsigned long getNextRunPeriod() = 0; // in milliseconds

};

class Task: public ITask
{
public:
    Task():m_countCycles(0){};
    virtual ~Task(){};

    unsigned long getCycles(){ return m_countCycles; }
    unsigned long incCycles(){ return ++m_countCycles; }

protected:
    unsigned long m_countCycles;
    Time m_timer;
};

class WriteLetter: public Task
{
public:
    void run()
    {
        cout << "--- Write letter--- " << incCycles() << endl;
    }

    unsigned long getNextRunPeriod()
    {
        m_timer.now();

        unsigned long next = m_timer + INTERVAL;

        cout << "Next period at " << next << "ms " << CYCLES - getCycles() << endl;

        next = (getCycles() < CYCLES ? next : 0);

        return next;
    }

private:
    enum{ INTERVAL = 1500, CYCLES = 6};
};


#endif //SCHEDULER_ELANAFELSI_TASK_H
