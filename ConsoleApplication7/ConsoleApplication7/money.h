#pragma once

#include "pair.h"

class Money : public Pair {
private:
    long* rubles;
    unsigned char* kopecks;

public:
    Money(long rub = 0, unsigned char kop = 0);
    Money(const Money& other);
    Money& operator=(Money& other);
    ~Money();

    virtual Pair* add(const Pair& other) const;
    virtual Pair* subtract(const Pair& other) const;
    virtual Pair* multiply(double scalar) const;
    virtual Pair* divide(double scalar) const;
    virtual void input(istream& in);
    virtual void display(ostream& out) const;
    virtual int compare(const Pair& other) const;

private:
    void normalize();
    double toDouble() const;
};