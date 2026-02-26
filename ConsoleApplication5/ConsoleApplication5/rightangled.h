#pragma once

#include "triangle.h"
#include <string>

class RightAngled : public Triangle {
private:
    double* area;
    bool isRightAngled(double a, double b, double c) const;
    void cleanupRightAngled();

public:
    RightAngled();
    RightAngled(double a, double b, double c);
    RightAngled(const RightAngled& other);
    RightAngled& operator=(const RightAngled& other);

    void setSideA(double a);
    void setSideB(double b);
    void setSideC(double c);
    void setSides(double a, double b, double c);
    void changeSides(double da, double db, double dc);

    double getHypotenuse() const;
    double getCathetus1() const;
    double getCathetus2() const;
    bool checkPythagoreanTheorem() const;

    double getArea() const;
    double calculateAreaByCatheti() const;
    void updateArea();

    operator std::string() const;
    void print() const;

    bool hasRightAngle() const;
    virtual ~RightAngled();
};