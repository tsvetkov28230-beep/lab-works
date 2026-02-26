#pragma once

#include <vector>
#include <string>
#include <iostream>

class Money {
private:
    static const std::vector<double> RUBLE_DENOMINATIONS;
    static const std::vector<double> KOPECK_DENOMINATIONS;

    int* ruble_counts;
    int* kopeck_counts;

    size_t* rcount;
    size_t* kcount;

    void initializeCounts();
    void resetCounts();
    void copyFrom(const Money& other);

public:
    Money();
    Money(double amount);
    Money(const Money& other);
    ~Money();

    Money& operator=(const Money& other);

    void setAmount(double amount);
    void addBill(double denomination);
    double getAmount() const;
    std::string getInfo() const;
    std::vector<double> getRublesBreakdown() const;
    std::vector<double> getKopecksBreakdown() const;

    Money operator+(const Money& other) const;
    Money& operator+=(const Money& other);
    Money operator-(const Money& other) const;
    Money& operator-=(const Money& other);

    Money operator+(double amount) const;
    Money& operator+=(double amount);
    Money operator-(double amount) const;
    Money& operator-=(double amount);
    Money operator*(double factor) const;
    Money& operator*=(double factor);

    double toDouble() const;

    const int* getRubleCounts() const { return ruble_counts; }
    const int* getKopeckCounts() const { return kopeck_counts; }
    size_t getRubleDenominationsCount() const { return *rcount; }
    size_t getKopeckDenominationsCount() const { return *kcount; }
    const std::vector<double>& getRubleDenominations() const { return RUBLE_DENOMINATIONS; }
    const std::vector<double>& getKopeckDenominations() const { return KOPECK_DENOMINATIONS; }

    bool operator==(const Money& other) const;
    bool operator!=(const Money& other) const;
    bool operator<(const Money& other) const;
    bool operator>(const Money& other) const;
    bool operator<=(const Money& other) const;
    bool operator>=(const Money& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Money& money);
    friend std::istream& operator>>(std::istream& is, Money& money);
};