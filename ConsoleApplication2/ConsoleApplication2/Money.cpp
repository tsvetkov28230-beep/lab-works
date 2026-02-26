#include "Money.h"
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <sstream>
#include <iomanip>

const std::vector<double> Money::RUBLE_DENOMINATIONS = { 1, 2, 5, 10, 100, 200, 500, 1000, 2000, 5000 };
const std::vector<double> Money::KOPECK_DENOMINATIONS = { 0.01, 0.05, 0.1, 0.5 };

Money::Money() : ruble_counts(nullptr), kopeck_counts(nullptr), rcount(nullptr), kcount(nullptr) {
    initializeCounts();
}

Money::Money(double amount) : ruble_counts(nullptr), kopeck_counts(nullptr), rcount(nullptr), kcount(nullptr) {
    initializeCounts();
    setAmount(amount);
}

Money::Money(const Money& other) : ruble_counts(nullptr), kopeck_counts(nullptr), rcount(nullptr), kcount(nullptr) {
    initializeCounts();
    copyFrom(other);
}

Money::~Money() {
    delete[] ruble_counts;
    delete[] kopeck_counts;
    delete rcount;
    delete kcount;
}

Money& Money::operator=(const Money& other) {
    if (this != &other) {
        copyFrom(other);
    }
    return *this;
}

void Money::initializeCounts() {
    rcount = new size_t(RUBLE_DENOMINATIONS.size());
    kcount = new size_t(KOPECK_DENOMINATIONS.size());

    ruble_counts = new int[*rcount];
    kopeck_counts = new int[*kcount];

    resetCounts();
}

void Money::resetCounts() {
    for (size_t i = 0; i < *rcount; ++i) {
        ruble_counts[i] = 0;
    }
    for (size_t i = 0; i < *kcount; ++i) {
        kopeck_counts[i] = 0;
    }
}

void Money::copyFrom(const Money& other) {
    for (size_t i = 0; i < *rcount; ++i) {
        ruble_counts[i] = other.ruble_counts[i];
    }
    for (size_t i = 0; i < *kcount; ++i) {
        kopeck_counts[i] = other.kopeck_counts[i];
    }
}

void Money::setAmount(double amount) {
    if (amount < 0) {
        throw std::invalid_argument("Сумма не может быть отрицательной");
    }

    resetCounts();

    double rubles = std::floor(amount);
    double remainder = amount - rubles;

    for (int i = static_cast<int>(*rcount) - 1; i >= 0 && rubles > 0; --i) {
        double denomination = RUBLE_DENOMINATIONS[i];
        if (denomination <= rubles) {
            ruble_counts[i] = static_cast<int>(rubles / denomination);
            rubles -= ruble_counts[i] * denomination;
        }
    }

    remainder += rubles;
    for (int i = static_cast<int>(*kcount) - 1; i >= 0 && remainder > 1e-9; --i) {
        double denomination = KOPECK_DENOMINATIONS[i];
        if (denomination <= remainder + 1e-9) {
            kopeck_counts[i] = static_cast<int>(remainder / denomination + 1e-9);
            remainder -= kopeck_counts[i] * denomination;
        }
    }
}

void Money::addBill(double denomination) {
    bool found = false;

    for (size_t i = 0; i < *rcount; ++i) {
        if (std::abs(RUBLE_DENOMINATIONS[i] - denomination) < 1e-9) {
            ruble_counts[i]++;
            found = true;
            break;
        }
    }

    if (!found) {
        for (size_t i = 0; i < *kcount; ++i) {
            if (std::abs(KOPECK_DENOMINATIONS[i] - denomination) < 1e-9) {
                kopeck_counts[i]++;
                found = true;
                break;
            }
        }
    }
}

double Money::getAmount() const {
    double total = 0.0;

    for (size_t i = 0; i < *rcount; ++i) {
        total += ruble_counts[i] * RUBLE_DENOMINATIONS[i];
    }

    for (size_t i = 0; i < *kcount; ++i) {
        total += kopeck_counts[i] * KOPECK_DENOMINATIONS[i];
    }

    return total;
}

double Money::toDouble() const {
    return getAmount();
}

std::string Money::getInfo() const {
    std::ostringstream oss;

    bool hasRubles = false;
    for (size_t i = 0; i < *rcount; ++i) {
        if (ruble_counts[i] > 0) {
            oss << "  " << RUBLE_DENOMINATIONS[i] << " руб: " << ruble_counts[i] << " шт.\n";
            hasRubles = true;
        }
    }
    if (!hasRubles) {
        oss << "  Рубли: 0" << std::endl;
    }
    bool hasKopeks = false;
    for (size_t i = 0; i < *kcount; ++i) {
        if (kopeck_counts[i] > 0) {
            oss << "  " << KOPECK_DENOMINATIONS[i] << " руб (" << (KOPECK_DENOMINATIONS[i] * 100) << " коп): " << kopeck_counts[i] << " шт." << std::endl;
            hasKopeks = true;
        }
    }
    if (!hasKopeks) {
        oss << "  Копейки: 0" << std::endl;
    }

    oss << "Общая сумма: " << std::fixed << std::setprecision(2) << getAmount() << " руб.\n";
    return oss.str();
}

std::vector<double> Money::getRublesBreakdown() const {
    std::vector<double> breakdown;
    for (size_t i = 0; i < *rcount; ++i) {
        for (int j = 0; j < ruble_counts[i]; ++j) {
            breakdown.push_back(RUBLE_DENOMINATIONS[i]);
        }
    }
    return breakdown;
}

std::vector<double> Money::getKopecksBreakdown() const {
    std::vector<double> breakdown;
    for (size_t i = 0; i < *kcount; ++i) {
        for (int j = 0; j < kopeck_counts[i]; ++j) {
            breakdown.push_back(KOPECK_DENOMINATIONS[i]);
        }
    }
    return breakdown;
}

Money Money::operator+(const Money& other) const {
    Money result(*this);
    result += other;
    return result;
}

Money& Money::operator+=(const Money& other) {
    double newAmount = this->getAmount() + other.getAmount();
    this->setAmount(newAmount);
    return *this;
}

Money Money::operator-(const Money& other) const {
    Money result(*this);
    result -= other;
    return result;
}

Money& Money::operator-=(const Money& other) {
    double newAmount = this->getAmount() - other.getAmount();
    if (newAmount < 0) {
        throw std::invalid_argument("Результат вычитания не может быть отрицательным");
    }
    this->setAmount(newAmount);
    return *this;
}

Money Money::operator+(double amount) const {
    Money result(*this);
    result.setAmount(result.getAmount() + amount);
    return result;
}

Money& Money::operator+=(double amount) {
    setAmount(getAmount() + amount);
    return *this;
}

Money Money::operator-(double amount) const {
    Money result(*this);
    result.setAmount(result.getAmount() - amount);
    return result;
}

Money& Money::operator-=(double amount) {
    setAmount(getAmount() - amount);
    return *this;
}

Money Money::operator*(double factor) const {
    Money result(*this);
    result.setAmount(result.getAmount() * factor);
    return result;
}

Money& Money::operator*=(double factor) {
    setAmount(getAmount() * factor);
    return *this;
}

bool Money::operator==(const Money& other) const {
    return std::abs(getAmount() - other.getAmount()) < 1e-9;
}

bool Money::operator!=(const Money& other) const {
    return !(*this == other);
}

bool Money::operator<(const Money& other) const {
    return getAmount() < other.getAmount();
}

bool Money::operator>(const Money& other) const {
    return getAmount() > other.getAmount();
}

bool Money::operator<=(const Money& other) const {
    return getAmount() <= other.getAmount();
}

bool Money::operator>=(const Money& other) const {
    return getAmount() >= other.getAmount();
}

std::ostream& operator<<(std::ostream& os, const Money& money) {
    os << money.getAmount() << " руб.";
    return os;
}

std::istream& operator>>(std::istream& is, Money& money) {
    double amount;
    is >> amount;
    money.setAmount(amount);
    return is;
}