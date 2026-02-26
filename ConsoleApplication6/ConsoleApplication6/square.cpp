#include "square.h"
#include <iostream>
#include <cmath>
using namespace std;

Square::Square(double a_val, double b_val, double c_val) {
    a = new double(a_val);
    b = new double(b_val);
    c = new double(c_val);
    root1 = new double(0);
    root2 = new double(0);
    numRoots = new int(0);
}

Square::Square(const Square& other) : Root(other) {
    a = new double(*(other.a));
    b = new double(*(other.b));
    c = new double(*(other.c));
    root1 = new double(*(other.root1));
    root2 = new double(*(other.root2));
    numRoots = new int(*(other.numRoots));
}

Square& Square::operator=(Square& other)
{
    *a = *other.a;
    *b = *other.b;
    *c = *other.c;
    *root1 = *other.root1;
    *root2 = *other.root2;
    *numRoots = *other.numRoots;
    return *this;
}

Square::~Square() {
    delete a;
    delete b;
    delete c;
    delete root1;
    delete root2;
    delete numRoots;
}

void Square::calculate() {
    if (*a == 0) {
        if (*b == 0) {
            if (*c == 0) *numRoots = -1;
            else *numRoots = 0;
        }
        else {
            *numRoots = 1;
            *root1 = -(*c) / (*b);
            *root2 = *root1;
        }
    }
    else {
        double D = (*b) * (*b) - 4 * (*a) * (*c);

        if (D < 0) {
            *numRoots = 0;
        }
        else if (D == 0) {
            *numRoots = 1;
            *root1 = -(*b) / (2 * (*a));
            *root2 = *root1;
        }
        else {
            *numRoots = 2;
            *root1 = (-(*b) + sqrt(D)) / (2 * (*a));
            *root2 = (-(*b) - sqrt(D)) / (2 * (*a));
        }
    }
}

void Square::display() const {
    if (*a==1) cout << "x^2";
    else cout << *a << "x^2";
    if (*b >= 0) cout << " + " << *b;
    else cout << " - " << -(*b);
    cout << "x";
    if (*c >= 0) cout << " + " << *c;
    else cout << " - " << -(*c);
    cout << " = 0" << endl;

    if (*numRoots == -1) cout << "Бесконечно решений" << endl;
    else if (*numRoots == 0) cout << "Нет корней" << endl;
    else if (*numRoots == 1) cout << "x = " << *root1 << endl;
    else cout << "x1 = " << *root1 << ", x2 = " << *root2 << endl;
}

void Square::input() {
    cout << "a: ";
    cin >> *a;
    cout << "b: ";
    cin >> *b;
    cout << "c: ";
    cin >> *c;
}