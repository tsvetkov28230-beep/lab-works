#pragma once
#include "Date.h"

class Payment
{
private:
    std::string employeeName;
    double* baseSalary;
    Date* employmentDate;
    double* bonusRate;
    double* taxRate;
    int* daysCompleted;
    int* totalWorkDays;
    double* totalEarnings;
    double* totalDeductions;

public:
    Payment();
    Payment(const std::string& name_, double salary_, const Date& startDate_,
        double bonusPercent_, int workedDays_, int totalDays_);
    Payment(const Payment& other);
    Payment& operator=(const Payment& other);
    ~Payment();

    void setEmployeeName(const std::string& name_);
    void setBaseSalary(double salary_);
    void setEmploymentDate(const Date& startDate_);
    void setBonusRate(double bonusPercent_);
    void setDaysCompleted(int workedDays_);
    void setTotalWorkDays(int totalDays_);

    std::string getEmployeeName() const;
    double getBaseSalary() const;
    Date getEmploymentDate() const;
    double getBonusRate() const;
    int getDaysCompleted() const;
    int getTotalWorkDays() const;
    double getTotalEarnings() const;
    double getTotalDeductions() const;

    void computeEarnings();
    void computeDeductions();
    double netSalary() const;
    int calculateExperience() const;

    friend std::ostream& operator<<(std::ostream& os, const Payment& payroll);
};
