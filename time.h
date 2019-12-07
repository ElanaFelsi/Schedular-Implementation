#ifndef SCHEDULER_ELANAFELSI_TIME_H
#define SCHEDULER_ELANAFELSI_TIME_H


class Time
{
public:
    explicit Time(unsigned long t);
    void now();
    bool operator<=(Time &time);
    bool operator<(Time &time);
    bool operator>=(Time &time);
    bool operator>(Time &time);
    friend std::ostream &operator<<(std::ostream & out, const Time &time);

    Time&operator-=(Time &time);
    /*Timeoperator+(Time &time);*/

private:
    unsigned long m_time;
};

inline void Time::now()
{
    time_t t = time(NULL);
    ctime(&t);
}

inline bool Time::operator<=(Time &time)
{
    return (m_time <= time.m_time);
}

inline bool Time::operator<(Time &time) {
    return (m_time < time.m_time);
}

inline bool Time::operator>=(Time &time) {
    return (m_time >= time.m_time);
}

inline bool Time::operator>(Time &time) {
    return (m_time > time.m_time);
}

inline Time &Time::operator-=(Time &time) {
    m_time -= time.m_time;
    return *this;
}

inline std::ostream &operator<<(std::ostream &out, const Time &time)
{
    out << time.m_time;
    return out;
}

inline Time::Time(unsigned long t) :m_time(t){}

#endif //SCHEDULER_ELANAFELSI_TIME_H
