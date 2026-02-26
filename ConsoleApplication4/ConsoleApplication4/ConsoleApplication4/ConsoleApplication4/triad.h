#pragma once

#include <iostream>
#include <string>

class Triad {
protected:
    int* first;
    int* second;
    int* third;

    void cleanup();

public:
    Triad();
    Triad(int f, int s, int t);
    Triad(const Triad& other);
    Triad& operator=(const Triad& other);

    int getFirst() const;
    int getSecond() const;
    int getThird() const;

    void setFirst(int f);
    void setSecond(int s);
    void setThird(int t);
    void setTriad(int f, int s, int t);

    bool operator==(const Triad& other) const;
    bool operator!=(const Triad& other) const;
    bool operator<(const Triad& other) const;
    bool operator>(const Triad& other) const;
    bool operator<=(const Triad& other) const;
    bool operator>=(const Triad& other) const;

    virtual operator std::string() const;
    virtual void print() const;
    virtual ~Triad();
};