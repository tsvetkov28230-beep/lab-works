#include "fraction.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

Fraction::Fraction(long w, unsigned short f) {
    whole = new long(w);
    frac = new unsigned short(f);
    normalize();
}

Fraction::Fraction(const Fraction& other) {
    whole = new long(*(other.whole));
    frac = new unsigned short(*(other.frac));
}

Fraction& Fraction::operator=(Fraction& other)
{
    *whole = *other.whole;
    *frac = *other.frac;
    return *this;
}

Fraction::~Fraction() {
    delete whole;
    delete frac;
}

void Fraction::normalize() {
    if (*frac >= 1000) {
        *whole += *frac / 1000;
        *frac %= 1000;
    }
}

double Fraction::toDouble() const {
    return *whole + *frac / 1000.0;
}

Pair* Fraction::add(const Pair& other) const {
    const Fraction& f = dynamic_cast<const Fraction&>(other);
    long resultWhole = *whole + *(f.whole);
    int resultFrac = *frac + *(f.frac);

    if (resultFrac >= 1000) {
        resultWhole += resultFrac / 1000;
        resultFrac %= 1000;
    }

    return new Fraction(resultWhole, static_cast<unsigned short>(resultFrac));
}

Pair* Fraction::subtract(const Pair& other) const {
    const Fraction& f = dynamic_cast<const Fraction&>(other);
    long resultWhole = *whole - *(f.whole);
    int resultFrac = *frac - *(f.frac);

    if (resultFrac < 0) {
        resultWhole -= 1;
        resultFrac += 1000;
    }

    return new Fraction(resultWhole, static_cast<unsigned short>(resultFrac));
}

Pair* Fraction::multiply(double scalar) const {
    double result = toDouble() * scalar;
    return new Fraction(static_cast<long>(result),
        static_cast<unsigned short>((result - static_cast<long>(result)) * 1000 + 0.5));
}

Pair* Fraction::divide(double scalar) const {
    if (fabs(scalar) < 1e-10) {
        return new Fraction(0, 0);
    }
    double result = toDouble() / scalar;
    return new Fraction(static_cast<long>(result),
        static_cast<unsigned short>((result - static_cast<long>(result)) * 1000 + 0.5));
}

void Fraction::input(istream& in) {
    in >> *whole;
    int f;
    in >> f;
    *frac = static_cast<unsigned short>(f);
    normalize();
}

void Fraction::display(ostream& out) const {
    out << *whole << ".";
    out << setw(3) << setfill('0') << *frac;
}

int Fraction::compare(const Pair& other) const {
    const Fraction& f = dynamic_cast<const Fraction&>(other);
    if (toDouble() > f.toDouble()) return 1;
    if (toDouble() < f.toDouble()) return -1;
    return 0;
}