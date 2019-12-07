#ifndef SCHEDULER_ELANAFELSI_TIME_H
#define SCHEDULER_ELANAFELSI_TIME_H


class Time
{
public:
    void now();
    /*operator<=
    operator<
    operator>=
    operator>
    operator+*/
private:
    unsigned long m_time;
};

inline void Time::now()
{
    time_t t = time(NULL);
    ctime(&t);
}

#endif //SCHEDULER_ELANAFELSI_TIME_H
