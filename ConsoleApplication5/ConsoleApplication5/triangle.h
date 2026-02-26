#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Triangle {
protected:
    double* sideA;
    double* sideB;
    double* sideC;

    bool isValidTriangle(double a, double b, double c) const;
    double toRadians(double degrees) const;
    double toDegrees(double radians) const;
    void cleanup();

public:
    Triangle();
    Triangle(double a, double b, double c);
    Triangle(const Triangle& other);
    Triangle& operator=(const Triangle& other);

    double getSideA() const;
    double getSideB() const;
    double getSideC() const;

    void setSideA(double a);
    void setSideB(double b);
    void setSideC(double c);
    void setSides(double a, double b, double c);
    void changeSides(double da, double db, double dc);

    double getAngleA() const;
    double getAngleB() const;
    double getAngleC() const;

    double getPerimeter() const;
    virtual double getArea() const;

    virtual operator std::string() const;
    virtual void print() const;
    virtual ~Triangle();
};