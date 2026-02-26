#include "time.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cstdio>

using namespace std;

void Time::cleanupTime() {
    delete isAM;
    isAM = nullptr;
}

Time::Time() : Triad(12, 0, 0) {
    isAM = new bool(true);
}

Time::Time(int hour12, int minute, int sec, bool am) : isAM(new bool(am)) {
    if (hour12 < 1 || hour12 > 12) {
        cout << "Ошибка: час должен быть от 1 до 12!" << endl;
        exit(1);
    }
    if (minute < 0 || minute > 59) {
        cout << "Ошибка: минуты должны быть от 0 до 59!" << endl;
        exit(1);
    }
    if (sec < 0 || sec > 59) {
        cout << "Ошибка: секунды должны быть от 0 до 59!" << endl;
        exit(1);
    }

    *first = hour12;
    *second = minute;
    *third = sec;
}

Time::Time(int hour24, int minute, int sec) : isAM(new bool(true)) {
    if (hour24 < 0 || hour24 > 23) {
        cout << "Ошибка: час должен быть от 0 до 23!" << endl;
        exit(1);
    }
    if (minute < 0 || minute > 59) {
        cout << "Ошибка: минуты должны быть от 0 до 59!" << endl;
        exit(1);
    }
    if (sec < 0 || sec > 59) {
        cout << "Ошибка: секунды должны быть от 0 до 59!" << endl;
        exit(1);
    }

    if (hour24 == 0) {
        *first = 12;
        *isAM = true;
    }
    else if (hour24 == 12) {
        *first = 12;
        *isAM = false;
    }
    else if (hour24 > 0 && hour24 < 12) {
        *first = hour24;
        *isAM = true;
    }
    else {
        *first = hour24 - 12;
        *isAM = false;
    }

    *second = minute;
    *third = sec;
}

Time::Time(const Time& other) : Time() {
    *this = other;
    //first = new int(*other.first);
    //second = new int(*other.second);
    //third = new int(*other.third);
    //isAM = new bool(*other.isAM);
}

Time& Time::operator=(const Time& other) {
    if (this != &other) {
        Triad::operator=(other);
        cleanupTime();
        *isAM = (*other.isAM);
    }
    return *this;
}

Time::~Time() {
    cleanupTime();
}

int Time::getHour() const { return *first; }
int Time::getMinute() const { return *second; }
int Time::getSecond() const { return *third; }
bool Time::getIsAM() const { return *isAM; }

int Time::getHour24() const {
    if (*first == 12) {
        return *isAM ? 0 : 12;
    }
    return *isAM ? *first : *first + 12;
}

void Time::setHour(int hour) {
    if (hour < 1 || hour > 12) {
        cout << "Ошибка: час должен быть от 1 до 12!" << endl;
        exit(1);
    }
    *first = hour;
}

void Time::setMinute(int minute) {
    if (minute < 0 || minute > 59) {
        cout << "Ошибка: минуты должны быть от 0 до 59!" << endl;
        exit(1);
    }
    *second = minute;
}

void Time::setSecond(int sec) {
    if (sec < 0 || sec > 59) {
        cout << "Ошибка: секунды должны быть от 0 до 59!" << endl;
        exit(1);
    }
    *third = sec;
}

void Time::setAM(bool am) {
    *isAM = am;
}

void Time::setTime(int hour, int minute, int second, bool am) {
    setHour(hour);
    setMinute(minute);
    setSecond(second);
    *isAM = am;
}

void Time::setTime24(int hour24, int minute, int second) {
    if (hour24 < 0 || hour24 > 23) {
        cout << "Ошибка: час должен быть от 0 до 23!" << endl;
        exit(1);
    }

    if (hour24 == 0) {
        *first = 12;
        *isAM = true;
    }
    else if (hour24 == 12) {
        *first = 12;
        *isAM = false;
    }
    else if (hour24 > 0 && hour24 < 12) {
        *first = hour24;
        *isAM = true;
    }
    else {
        *first = hour24 - 12;
        *isAM = false;
    }

    setMinute(minute);
    setSecond(second);
}

void Time::setTriad(int hour, int minute, int second) {
    setTime(hour, minute, second, true);
}

Time::operator string() const {
    char buffer[100];
    snprintf(buffer, sizeof(buffer),
        "%02d:%02d:%02d %s (24h: %02d:%02d:%02d)",
        *first, *second, *third,
        *isAM ? "AM" : "PM",
        getHour24(), *second, *third);
    return string(buffer);
}

void Time::print() const {
    cout << string(*this) << endl;
}

bool Time::operator==(const Time& other) const {
    return (getHour24() == other.getHour24()) &&
        (*second == *other.second) &&
        (*third == *other.third);
}

bool Time::operator!=(const Time& other) const {
    return !(*this == other);
}

bool Time::operator<(const Time& other) const {
    if (getHour24() != other.getHour24()) {
        return getHour24() < other.getHour24();
    }
    if (*second != *other.second) {
        return *second < *other.second;
    }
    return *third < *other.third;
}

bool Time::operator>(const Time& other) const {
    return other < *this;
}

bool Time::operator<=(const Time& other) const {
    return !(*this > other);
}

bool Time::operator>=(const Time& other) const {
    return !(*this < other);
}