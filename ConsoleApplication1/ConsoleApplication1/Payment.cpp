#include"Payment.h"
using std::cout;
using std::endl;

Payment::Payment()
{
    baseSalary = new double(0);
    employmentDate = new Date();
    bonusRate = new double(0);
    taxRate = new double(13);
    daysCompleted = new int(0);
    totalWorkDays = new int(0);
    totalEarnings = new double(0);
    totalDeductions = new double(0);
}

Payment::Payment(const std::string& name_, double salary_, const Date& startDate_,
    double bonusPercent_, int workedDays_, int totalDays_) : employeeName(name_)
{
    baseSalary = new double(salary_);
    employmentDate = new Date(startDate_);
    bonusRate = new double(bonusPercent_);
    taxRate = new double(13);
    daysCompleted = new int(workedDays_);
    totalWorkDays = new int(totalDays_);
    totalEarnings = new double(0);
    totalDeductions = new double(0);
}

Payment::Payment(const Payment& other) : employeeName(other.employeeName)
{
    baseSalary = new double(*other.baseSalary);
    employmentDate = new Date(*other.employmentDate);
    bonusRate = new double(*other.bonusRate);
    taxRate = new double(*other.taxRate);
    daysCompleted = new int(*other.daysCompleted);
    totalWorkDays = new int(*other.totalWorkDays);
    totalEarnings = new double(*other.totalEarnings);
    totalDeductions = new double(*other.totalDeductions);
}

Payment& Payment::operator=(const Payment& other)
{
    if (this != &other)
    {
        *baseSalary = *other.baseSalary;
        *employmentDate = *other.employmentDate;
        *bonusRate = *other.bonusRate;
        *taxRate = *other.taxRate;
        *daysCompleted = *other.daysCompleted;
        *totalWorkDays = *other.totalWorkDays;
        *totalEarnings = *other.totalEarnings;
        *totalDeductions = *other.totalDeductions;
        employeeName = other.employeeName;
    }
    return *this;
}

Payment::~Payment()
{
    delete baseSalary;
    delete employmentDate;
    delete bonusRate;
    delete taxRate;
    delete daysCompleted;
    delete totalWorkDays;
    delete totalEarnings;
    delete totalDeductions;
}

void Payment::setEmployeeName(const std::string& name_)
{
    employeeName = name_;
}

void Payment::setBaseSalary(double salary_)
{
    *baseSalary = salary_;
}

void Payment::setEmploymentDate(const Date& startDate_)
{
    *employmentDate = startDate_;
}

void Payment::setBonusRate(double bonusPercent_)
{
    *bonusRate = bonusPercent_;
}

void Payment::setDaysCompleted(int workedDays_)
{
    *daysCompleted = workedDays_;
}

void Payment::setTotalWorkDays(int totalDays_)
{
    *totalWorkDays = totalDays_;
}

std::string Payment::getEmployeeName() const
{
    return employeeName;
}

double Payment::getBaseSalary() const
{
    return *baseSalary;
}

Date Payment::getEmploymentDate() const
{
    return *employmentDate;
}

double Payment::getBonusRate() const
{
    return *bonusRate;
}

int Payment::getDaysCompleted() const
{
    return *daysCompleted;
}

int Payment::getTotalWorkDays() const
{
    return *totalWorkDays;
}

double Payment::getTotalEarnings() const
{
    return *totalEarnings;
}

double Payment::getTotalDeductions() const
{
    return *totalDeductions;
}

void Payment::computeEarnings()
{
    if (*totalWorkDays <= 0 || *daysCompleted < 0 ||*baseSalary < 0)
    {
        *totalEarnings = 0;
        return;
    }
    unsigned int actualDays = (*daysCompleted > *totalWorkDays) ? *totalWorkDays : *daysCompleted;
    double baseEarnings = (*baseSalary / *totalWorkDays) * actualDays;
    double bonusAmount = baseEarnings * (*bonusRate / 100.0);

    *totalEarnings = baseEarnings + bonusAmount;
}

void Payment::computeDeductions()
{
    computeEarnings();

    if (*totalEarnings <= 0 || *taxRate < 0)
    {
        *totalDeductions = 0;
        return;
    }
    const double PENSION_CONTRIBUTION = 0.01;
    const double effectiveTax = (*taxRate > 100) ? 1.0 : (*taxRate / 100.0);
    double pensionDeduction = *totalEarnings * PENSION_CONTRIBUTION;
    double incomeTax = (*totalEarnings - pensionDeduction) * effectiveTax;

    *totalDeductions = pensionDeduction + incomeTax;
}

double Payment::netSalary() const
{
    return *totalEarnings - *totalDeductions;
}

int Payment::calculateExperience() const
{
    Date currentDate = Date::getCurrentDate();
    Date startDate = *employmentDate;

    int years = currentDate.getCurrentYear() - employmentDate->getCurrentYear();
    int months = currentDate.getCurrentMonth() - employmentDate->getCurrentMonth();
    int days = currentDate.getCurrentDay() - employmentDate->getCurrentDay();
    if (months < 0 || (months == 0 && days < 0))
    {
        years--;
    }

    return std::max(0, years);
}

std::ostream& operator<<(std::ostream& os, const Payment& payroll)
{
    os << "Full name: " << payroll.employeeName << endl <<
        "Salary: " << *payroll.baseSalary << endl <<
        "Date of admission to work: " << payroll.employmentDate->toString() << endl <<
        "Percentage of the surcharge: " << *payroll.bonusRate << "%" << endl <<
        "Number of worked days: " << *payroll.daysCompleted << endl <<
        "Number of working days: " << *payroll.totalWorkDays << endl <<
        "Accured amount: " << *payroll.totalEarnings << endl <<
        "Withheld amount: " << *payroll.totalDeductions << endl <<
        "Real salary or amount on hand: " << payroll.netSalary() << endl <<
        "Seniority: " << 2025 - payroll.calculateExperience() << " years" << endl;

    return os;
}