#pragma once

#include <iostream>
using namespace std;

class Pair {
public:
    Pair();
    Pair(Pair& other);
    Pair& operator=(Pair& other);
    virtual Pair* add(const Pair& other) const = 0;
    virtual Pair* subtract(const Pair& other) const = 0;
    virtual Pair* multiply(double scalar) const = 0;
    virtual Pair* divide(double scalar) const = 0;
    virtual void input(istream& in) = 0;
    virtual void display(ostream& out) const = 0;
    virtual int compare(const Pair& other) const = 0;
    virtual ~Pair() {}
};