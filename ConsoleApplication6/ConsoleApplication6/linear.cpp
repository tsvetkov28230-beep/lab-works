#include "linear.h"
#include <iostream>
using namespace std;

Linear::Linear(double a_val, double b_val) {
    a = new double(a_val);
    b = new double(b_val);
    root = new double(0);
    infinite = new bool(false);
    noSolution = new bool(false);
}

Linear::Linear(const Linear& other) {
    a = new double(*(other.a));
    b = new double(*(other.b));
    root = new double(*(other.root));
    infinite = new bool(*(other.infinite));
    noSolution = new bool(*(other.noSolution));
}

Linear& Linear::operator=(Linear& other)
{
    if (this != &other)
    {
        Root::operator=(other);
        *a = *other.a;
        *b = *other.b;
        *root = *other.root;
        *infinite = *other.infinite;
        *noSolution = *other.noSolution;
    }
    return *this;
}

Linear::~Linear() {
    delete a;
    delete b;
    delete root;
    delete infinite;
    delete noSolution;
}

void Linear::calculate() {
    if (*a == 0) {
        if (*b == 0) {
            *infinite = true;
            *noSolution = false;
        }
        else {
            *noSolution = true;
            *infinite = false;
        }
    }
    else {
        *root = -(*b) / (*a);
        *infinite = false;
        *noSolution = false;
    }
}

void Linear::display() const {
    if (*a == 1) cout << "x";
    else cout << *a << "x";
    if (*b >= 0) cout << " + " << *b;
    else cout << " - " << -(*b);
    cout << " = 0" << endl;

    if (*infinite) cout << "Бесконечно решений" << endl;
    else if (*noSolution) cout << "Нет решений" << endl;
    else cout << "x = " << *root << endl;
}

void Linear::input() {
    cout << "a: ";
    cin >> *a;
    cout << "b: ";
    cin >> *b;
}