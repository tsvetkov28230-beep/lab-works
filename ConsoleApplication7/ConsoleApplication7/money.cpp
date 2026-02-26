#include "money.h"
#include <iostream>
#include <cmath>
using namespace std;

Money::Money(long rub, unsigned char kop) {
    rubles = new long(rub);
    kopecks = new unsigned char(kop);
    normalize();
}

Money::Money(const Money& other) {
    rubles = new long(*(other.rubles));
    kopecks = new unsigned char(*(other.kopecks));
}

Money& Money::operator=(Money& other)
{
    *rubles = *other.rubles;
    *kopecks = *other.kopecks;
    return *this;
}

Money::~Money() {
    delete rubles;
    delete kopecks;
}

void Money::normalize() {
    if (*kopecks >= 100) {
        *rubles += *kopecks / 100;
        *kopecks %= 100;
    }
    if (*rubles < 0 && *kopecks > 0) {
        *rubles += 1;
        *kopecks = 100 - *kopecks;
    }
}

double Money::toDouble() const {
    return *rubles + *kopecks / 100.0;
}

Pair* Money::add(const Pair& other) const {
    const Money& m = dynamic_cast<const Money&>(other);
    long totalRub = *rubles + *(m.rubles);
    int totalKop = *kopecks + *(m.kopecks);

    if (totalKop >= 100) {
        totalRub += totalKop / 100;
        totalKop %= 100;
    }

    return new Money(totalRub, static_cast<unsigned char>(totalKop));
}

Pair* Money::subtract(const Pair& other) const {
    const Money& m = dynamic_cast<const Money&>(other);
    long totalRub = *rubles - *(m.rubles);
    int totalKop = *kopecks - *(m.kopecks);

    if (totalKop < 0) {
        totalRub -= 1;
        totalKop += 100;
    }

    return new Money(totalRub, static_cast<unsigned char>(totalKop));
}

Pair* Money::multiply(double scalar) const {
    double result = toDouble() * scalar;
    return new Money(static_cast<long>(result),
        static_cast<unsigned char>((result - static_cast<long>(result)) * 100 + 0.5));
}

Pair* Money::divide(double scalar) const {
    if (fabs(scalar) < 1e-10) {
        return new Money(0, 0);
    }
    double result = toDouble() / scalar;
    return new Money(static_cast<long>(result),
        static_cast<unsigned char>((result - static_cast<long>(result)) * 100 + 0.5));
}

void Money::input(istream& in) {
    in >> *rubles;
    int kop;
    in >> kop;
    *kopecks = static_cast<unsigned char>(kop);
    normalize();
}

void Money::display(ostream& out) const {
    out << *rubles << ",";
    if (*kopecks < 10) out << "0";
    out << static_cast<int>(*kopecks) << " руб.";
}


int Money::compare(const Pair& other) const {
    const Money& m = dynamic_cast<const Money&>(other);
    if (*rubles > *(m.rubles)) return 1;
    if (*rubles < *(m.rubles)) return -1;
    if (*kopecks > *(m.kopecks)) return 1;
    if (*kopecks < *(m.kopecks)) return -1;
    return 0;
}