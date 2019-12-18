#include <iostream>
#include <cstdio>
#include "scheduler.h"

int main()
{
    Scheduler s;

    s.addTask(new WriteLetter);

    s.run();

    return 0;
}