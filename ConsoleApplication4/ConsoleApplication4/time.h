#pragma once

#include "triad.h"
#include <string>

class Time : public Triad {
private:
    bool* isAM;
    void cleanupTime();

public:
    Time();
    Time(int hour12, int minute, int second, bool am);
    explicit Time(int hour24, int minute, int second);
    Time(const Time& other);
    Time& operator=(const Time& other);

    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    bool getIsAM() const;
    int getHour24() const;

    void setHour(int hour);
    void setMinute(int minute);
    void setSecond(int second);
    void setAM(bool am);
    void setTime(int hour, int minute, int second, bool am = true);
    void setTime24(int hour24, int minute, int second);
    void setTriad(int hour, int minute, int second);

    operator std::string() const override;
    void print() const override;

    bool operator==(const Time& other) const;
    bool operator!=(const Time& other) const;
    bool operator<(const Time& other) const;
    bool operator>(const Time& other) const;
    bool operator<=(const Time& other) const;
    bool operator>=(const Time& other) const;

    virtual ~Time();
};