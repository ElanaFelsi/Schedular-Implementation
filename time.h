#ifndef SCHEDULER_ELANAFELSI_TIME_H
#define SCHEDULER_ELANAFELSI_TIME_H

#include <iostream>
#include <ctime>

class Time
{
public:
    explicit Time(unsigned long time = 0);

    void now();

    bool operator<=(const Time &time);
    bool operator<(const Time &time);
    bool operator>=(const Time &time);
    bool operator>(const Time &time);

    friend std::ostream &operator<<(std::ostream & out, const Time &time);

    unsigned long operator-(const Time &other) const;
    unsigned long operator+(unsigned long interval) const;

    unsigned long GetTimeInMill() const;
private:
    unsigned long m_time;

    unsigned long GetTickCount() const;
};

inline Time::Time(unsigned long time) :m_time(time){}

inline void Time::now()
{
    m_time = GetTickCount();
}

inline bool Time::operator<=(const Time &time)
{
    return m_time <= time.GetTimeInMill();

}

inline bool Time::operator<(const Time &time) {
    return m_time < time.GetTimeInMill();
}

inline bool Time::operator>=(const Time &time) {
    return m_time >= time.GetTimeInMill();
}

inline bool Time::operator>(const Time &time) {
    return m_time > time.GetTimeInMill();
}


inline std::ostream &operator<<(std::ostream &out, const Time &time)
{
    out << time.m_time;
    return out;
}

unsigned long Time::GetTickCount() const {
    struct timespec  now = {0};

    if(clock_gettime(CLOCK_MONOTONIC, &now))
    {
        return 0;
    }

    return static_cast<unsigned long>(now.tv_sec * 1000 + now.tv_nsec / 1000000);
}

inline unsigned long Time::GetTimeInMill() const {
    return m_time;
}

unsigned long Time::operator-(const Time &other) const {
    return m_time - other.GetTimeInMill();
}

unsigned long Time::operator+(unsigned long interval) const {
    return m_time + interval;
}


#endif //SCHEDULER_ELANAFELSI_TIME_H
