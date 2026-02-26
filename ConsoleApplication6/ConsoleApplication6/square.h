#pragma once

#include "root.h"

class Square : public Root {
private:
    double* a;
    double* b;
    double* c;
    double* root1;
    double* root2;
    int* numRoots;

public:
    Square(double a_val = 0, double b_val = 0, double c_val = 0);
    Square(const Square& other);
    Square& operator=(Square& other);
    ~Square();

    virtual void calculate();
    virtual void display() const;

    void input();
};