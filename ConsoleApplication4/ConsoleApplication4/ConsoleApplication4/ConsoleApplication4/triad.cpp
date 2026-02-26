#include "triad.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void Triad::cleanup() {
    delete first;
    delete second;
    delete third;
    first = second = third = nullptr;
}

Triad::Triad() {
    first = new int(0);
    second = new int(0);
    third = new int(0);
}

Triad::Triad(int f, int s, int t) {
    if (f < 0 || s < 0 || t < 0) {
        cout << "Ошибка: числа должны быть неотрицательными!" << endl;
        exit(1);
    }
    first = new int(f);
    second = new int(s);
    third = new int(t);
}

Triad::Triad(const Triad& other) {
    first = new int(*other.first);
    second = new int(*other.second);
    third = new int(*other.third);
}

Triad& Triad::operator=(const Triad& other) {
    if (this != &other) {
        //cleanup();
        *first =  (*other.first);
        *second = (*other.second);
        *third = (*other.third);
    }
    return *this;
}

Triad::~Triad() {
    cleanup();
}

int Triad::getFirst() const { return *first; }
int Triad::getSecond() const { return *second; }
int Triad::getThird() const { return *third; }

void Triad::setFirst(int f) {
    if (f < 0) {
        cout << "Ошибка: число должно быть неотрицательным!" << endl;
        exit(1);
    }
    *first = f;
}

void Triad::setSecond(int s) {
    if (s < 0) {
        cout << "Ошибка: число должно быть неотрицательным!" << endl;
        exit(1);
    }
    *second = s;
}

void Triad::setThird(int t) {
    if (t < 0) {
        cout << "Ошибка: число должно быть неотрицательным!" << endl;
        exit(1);
    }
    *third = t;
}

void Triad::setTriad(int f, int s, int t) {
    if (f < 0 || s < 0 || t < 0) {
        cout << "Ошибка: числа должны быть неотрицательными!" << endl;
        exit(1);
    }
    *first = f;
    *second = s;
    *third = t;
}

bool Triad::operator==(const Triad& other) const {
    return (*first == *other.first) &&
        (*second == *other.second) &&
        (*third == *other.third);
}

bool Triad::operator!=(const Triad& other) const {
    return !(*this == other);
}

bool Triad::operator<(const Triad& other) const {
    if (*first != *other.first) {
        return *first < *other.first;
    }
    if (*second != *other.second) {
        return *second < *other.second;
    }
    return *third < *other.third;
}

bool Triad::operator>(const Triad& other) const {
    return other < *this;
}

bool Triad::operator<=(const Triad& other) const {
    return !(*this > other);
}

bool Triad::operator>=(const Triad& other) const {
    return !(*this < other);
}

Triad::operator string() const {
    return "(" + to_string(*first) + ", " + to_string(*second) + ", " + to_string(*third) + ")";
}

void Triad::print() const {
    cout << string(*this) << endl;
}