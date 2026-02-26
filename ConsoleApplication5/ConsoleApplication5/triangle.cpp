#include "triangle.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cstdio>

using namespace std;

const double PI = 3.14159265358979323846;

void Triangle::cleanup() {
    delete sideA;
    delete sideB;
    delete sideC;
    sideA = sideB = sideC = nullptr;
}

Triangle::Triangle() {
    sideA = new double(3.0);
    sideB = new double(4.0);
    sideC = new double(5.0);
}

Triangle::Triangle(double a, double b, double c) {
    if (!isValidTriangle(a, b, c)) {
        cout << "Ошибка: треугольник с такими сторонами не существует!" << endl;
        exit(1);
    }
    sideA = new double(a);
    sideB = new double(b);
    sideC = new double(c);
}

Triangle::Triangle(const Triangle& other) {
    sideA = new double(*other.sideA);
    sideB = new double(*other.sideB);
    sideC = new double(*other.sideC);
}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        cleanup();
        sideA = new double(*other.sideA);
        sideB = new double(*other.sideB);
        sideC = new double(*other.sideC);
    }
    return *this;
}

Triangle::~Triangle() {
    cleanup();
}

bool Triangle::isValidTriangle(double a, double b, double c) const {
    if (a <= 0 || b <= 0 || c <= 0) return false;
    return (a + b > c) && (a + c > b) && (b + c > a);
}

double Triangle::toRadians(double degrees) const {
    return degrees * PI / 180.0;
}

double Triangle::toDegrees(double radians) const {
    return radians * 180.0 / PI;
}

double Triangle::getSideA() const { return *sideA; }
double Triangle::getSideB() const { return *sideB; }
double Triangle::getSideC() const { return *sideC; }

void Triangle::setSideA(double a) {
    if (!isValidTriangle(a, *sideB, *sideC)) {
        cout << "Ошибка: сторона A недопустима!" << endl;
        exit(1);
    }
    *sideA = a;
}

void Triangle::setSideB(double b) {
    if (!isValidTriangle(*sideA, b, *sideC)) {
        cout << "Ошибка: сторона B недопустима!" << endl;
        exit(1);
    }
    *sideB = b;
}

void Triangle::setSideC(double c) {
    if (!isValidTriangle(*sideA, *sideB, c)) {
        cout << "Ошибка: сторона C недопустима!" << endl;
        exit(1);
    }
    *sideC = c;
}

void Triangle::setSides(double a, double b, double c) {
    if (!isValidTriangle(a, b, c)) {
        cout << "Ошибка: треугольник не существует!" << endl;
        exit(1);
    }
    *sideA = a;
    *sideB = b;
    *sideC = c;
}

void Triangle::changeSides(double da, double db, double dc) {
    double newA = *sideA + da;
    double newB = *sideB + db;
    double newC = *sideC + dc;

    if (!isValidTriangle(newA, newB, newC)) {
        cout << "Ошибка: изменение сторон делает треугольник невалидным!" << endl;
        exit(1);
    }

    *sideA = newA;
    *sideB = newB;
    *sideC = newC;
}

double Triangle::getAngleA() const {
    double a = *sideA, b = *sideB, c = *sideC;
    double cosA = (b * b + c * c - a * a) / (2 * b * c);
    if (cosA > 1.0) cosA = 1.0;
    if (cosA < -1.0) cosA = -1.0;
    return toDegrees(acos(cosA));
}

double Triangle::getAngleB() const {
    double a = *sideA, b = *sideB, c = *sideC;
    double cosB = (a * a + c * c - b * b) / (2 * a * c);
    if (cosB > 1.0) cosB = 1.0;
    if (cosB < -1.0) cosB = -1.0;
    return toDegrees(acos(cosB));
}

double Triangle::getAngleC() const {
    double a = *sideA, b = *sideB, c = *sideC;
    double cosC = (a * a + b * b - c * c) / (2 * a * b);
    if (cosC > 1.0) cosC = 1.0;
    if (cosC < -1.0) cosC = -1.0;
    return toDegrees(acos(cosC));
}

double Triangle::getPerimeter() const {
    return *sideA + *sideB + *sideC;
}

double Triangle::getArea() const {
    double p = getPerimeter() / 2;
    double a = *sideA, b = *sideB, c = *sideC;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

Triangle::operator string() const {
    char buffer[512];
    snprintf(buffer, sizeof(buffer),
        "Треугольник: a=%.2f, b=%.2f, c=%.2f\nУглы: ∠A=%.2f°, ∠B=%.2f°, ∠C=%.2f°\nПериметр: %.2f\nПлощадь: %.2f",
        *sideA, *sideB, *sideC, getAngleA(), getAngleB(), getAngleC(), getPerimeter(), getArea());
    return string(buffer);
}

void Triangle::print() const {
    cout << string(*this) << endl;
}