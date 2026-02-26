#pragma once

#include "root.h"

class Linear : public Root {
private:
    double* a;
    double* b;
    double* root;
    bool* infinite;
    bool* noSolution;

public:
    Linear(double a_val = 0, double b_val = 0);
    Linear(const Linear& other);
    Linear& operator=(Linear& other);
    ~Linear();

    virtual void calculate();
    virtual void display() const;

    void input();
};