#pragma once

#include "pair.h"

class Fraction : public Pair {
private:
    long* whole;
    unsigned short* frac;

public:
    Fraction(long w = 0, unsigned short f = 0);
    Fraction(const Fraction& other);
    Fraction& operator=(Fraction& other);
    ~Fraction();

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