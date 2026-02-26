#include "Date.h"
#include "Payment.h"

using std::cin;
using std::cout;
using std::endl;


int main()
{
    std::string employeeName{ "" };
    double baseSalary{ 0 };
    std::string dateInput{ "" };
    double bonusRate{ 0 };
    int daysCompleted{ 0 };
    int totalWorkDays{ 0 };
    cout << Date::getCurrentDate().toString() << endl;
    cout << "Enter full name: ";
    getline(cin, employeeName);

    cout << "Enter salary: ";
    cin >> baseSalary;

    cout << "Enter date of admission to work in the format (year.month.day): ";
    cin >> dateInput;

    cout << "Enter percentage of the surcharge: ";
    cin >> bonusRate;

    cout << "Enter the number of days worked: ";
    cin >> daysCompleted;

    cout << "Enter the number of working days in a month: ";
    cin >> totalWorkDays;

    Date hireDate = Date();
    int year{ 0 }, month{ 0 }, day{ 0 };
    if (sscanf_s(dateInput.c_str(), "year.month.day", &year, &month, &day) == 3)
    {
        hireDate = Date(year, month, day);
        cout << endl;
    }
    else
    {
        cout << "Incorrect date format. The default date is set: 2025.01.01" << endl;
        hireDate = Date(2025, 1, 1);
    }

    Payment worker(employeeName, baseSalary, hireDate, bonusRate, daysCompleted, totalWorkDays);

    worker.computeDeductions();

    cout << "**** Calculation results ****" << endl;
    cout << worker << endl;

    return 0;
}