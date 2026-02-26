#include "rightangled.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

void RightAngled::cleanupRightAngled() {
    delete area;
    area = nullptr;
}

RightAngled::RightAngled() : Triangle(3, 4, 5) {
    area = new double;
    updateArea();
}

RightAngled::RightAngled(double a, double b, double c) : Triangle(a, b, c) {
    if (!isRightAngled(a, b, c)) {
        cout << "Ошибка: треугольник не прямоугольный!" << endl;
        exit(1);
    }
    area = new double;
    updateArea();
}

RightAngled::RightAngled(const RightAngled& other)
{
    sideA = new double(*other.sideA);
    sideB = new double(*other.sideB);
    sideC = new double(*other.sideC);
    area = new double(*other.area);
}

RightAngled& RightAngled::operator=(const RightAngled& other) {
    if (this != &other) {
        Triangle::operator=(other);
        cleanupRightAngled();
        area = new double(*other.area);
    }
    return *this;
}

RightAngled::~RightAngled() {
    cleanupRightAngled();
}

bool RightAngled::isRightAngled(double a, double b, double c) const {
    double sides[3] = { a, b, c };
    sort(sides, sides + 3);
    double tolerance = 1e-6;
    return fabs(sides[2] * sides[2] - (sides[0] * sides[0] + sides[1] * sides[1])) < tolerance;
}

bool RightAngled::checkPythagoreanTheorem() const {
    double a = *sideA, b = *sideB, c = *sideC;
    double maxSide = max(max(a, b), c);
    double cathetus1, cathetus2;

    if (maxSide == a) { cathetus1 = b; cathetus2 = c; }
    else if (maxSide == b) { cathetus1 = a; cathetus2 = c; }
    else { cathetus1 = a; cathetus2 = b; }

    double tolerance = 1e-6;
    return fabs(maxSide * maxSide - (cathetus1 * cathetus1 + cathetus2 * cathetus2)) < tolerance;
}

void RightAngled::setSideA(double a) {
    if (!isRightAngled(a, *sideB, *sideC)) {
        cout << "Ошибка: нарушение прямоугольности!" << endl;
        exit(1);
    }
    *sideA = a;
    updateArea();
}

void RightAngled::setSideB(double b) {
    if (!isRightAngled(*sideA, b, *sideC)) {
        cout << "Ошибка: нарушение прямоугольности!" << endl;
        exit(1);
    }
    *sideB = b;
    updateArea();
}

void RightAngled::setSideC(double c) {
    if (!isRightAngled(*sideA, *sideB, c)) {
        cout << "Ошибка: нарушение прямоугольности!" << endl;
        exit(1);
    }
    *sideC = c;
    updateArea();
}

void RightAngled::setSides(double a, double b, double c) {
    if (!isRightAngled(a, b, c)) {
        cout << "Ошибка: треугольник не прямоугольный!" << endl;
        exit(1);
    }
    *sideA = a;
    *sideB = b;
    *sideC = c;
    updateArea();
}

void RightAngled::changeSides(double da, double db, double dc) {
    double newA = *sideA + da;
    double newB = *sideB + db;
    double newC = *sideC + dc;

    if (!isRightAngled(newA, newB, newC)) {
        cout << "Ошибка: изменение сторон нарушает прямоугольность!" << endl;
        exit(1);
    }

    *sideA = newA;
    *sideB = newB;
    *sideC = newC;
    updateArea();
}

double RightAngled::getHypotenuse() const {
    return max(max(*sideA, *sideB), *sideC);
}

double RightAngled::getCathetus1() const {
    double hyp = getHypotenuse();
    if (*sideA != hyp) return *sideA;
    return *sideB;
}

double RightAngled::getCathetus2() const {
    double hyp = getHypotenuse();
    if (*sideC != hyp) return *sideC;
    return *sideB;
}

double RightAngled::getArea() const {
    return *area;
}

double RightAngled::calculateAreaByCatheti() const {
    double cathetus1 = getCathetus1();
    double cathetus2 = getCathetus2();
    return (cathetus1 * cathetus2) / 2.0;
}

void RightAngled::updateArea() {
    *area = calculateAreaByCatheti();
}

bool RightAngled::hasRightAngle() const {
    double tolerance = 1e-2;
    return fabs(getAngleA() - 90) < tolerance ||
        fabs(getAngleB() - 90) < tolerance ||
        fabs(getAngleC() - 90) < tolerance;
}

RightAngled::operator string() const {
    char buffer[1024];
    snprintf(buffer, sizeof(buffer),
        "Прямоугольный треугольник:\nСтороны: a=%.2f, b=%.2f, c=%.2f\n"
        "Гипотенуза: %.2f\nКатеты: %.2f и %.2f\nУглы: A=%.2f°, B=%.2f°, C=%.2f°\n"
        "Периметр: %.2f\nПлощадь: %.2f\nТеорема Пифагора: %s",
        *sideA, *sideB, *sideC, getHypotenuse(), getCathetus1(), getCathetus2(),
        getAngleA(), getAngleB(), getAngleC(), getPerimeter(), getArea(),
        checkPythagoreanTheorem() ? "Да" : "Нет");
    return string(buffer);
}

void RightAngled::print() const {
    cout << string(*this) << endl;
}