#include "Date.h"

Date::Date()
{
    currentYear = new unsigned int(2025);
    currentMonth = new unsigned int(10);
    currentDay = new unsigned int(31);
}

Date::Date(unsigned int year_, unsigned int month_, unsigned int day_)
{
    currentYear = new unsigned int(year_);
    currentMonth = new unsigned int(month_);
    currentDay = new unsigned int(day_);
}

Date::Date(const Date& otherDate)
{
    currentYear = new unsigned int(*otherDate.currentYear);
    currentMonth = new unsigned int(*otherDate.currentMonth);
    currentDay = new unsigned int(*otherDate.currentDay);
}

Date::Date(const std::string& dateString)
{
    currentYear = new unsigned int(2025);
    currentMonth = new unsigned int(10);
    currentDay = new unsigned int(31);

    char separator1{ ' ' }, separator2{ ' ' };
    std::stringstream ss(dateString);
    unsigned int inputYear, inputMonth, inputDay;

    ss >> inputYear >> separator1 >> inputMonth >> separator2 >> inputDay;

    if (separator1 == '.' && separator2 == '.')
    {
        *currentYear = inputYear;
        *currentMonth = inputMonth;
        *currentDay = inputDay;
    }
}

Date& Date::operator=(const Date& other)
{
    if (this != &other)
    {
        *currentYear = *other.currentYear;
        *currentMonth = *other.currentMonth;
        *currentDay = *other.currentDay;
    }
    return *this;
}

Date::~Date()
{
    delete currentYear;
    delete currentMonth;
    delete currentDay;
}

unsigned int Date::getCurrentYear()
{
    return *currentYear;
}

unsigned int Date::getCurrentMonth()
{
    return *currentMonth;
}

unsigned int Date::getCurrentDay()
{
    return *currentDay;
}

void Date::setCurrentYear(unsigned int year_)
{
    *currentYear = year_;
}

void Date::setCurrentMonth(unsigned int month_)
{
    *currentMonth = month_;
}

void Date::setCurrentDay(unsigned int day_)
{
    *currentDay = day_;
}

int Date::getDaysInMonth(int month, int year) const
{
    switch (month)
    {
    case 2:
        return checkLeapYear(year) ? 29 : 28;
    case 4: case 6: case 9: case 11:
        return 30;
    default:
        return 31;
    }
}

bool Date::checkLeapYear(int year) const
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

Date Date::getCurrentDate()
{
    std::time_t t = std::time(nullptr);
    std::tm now;

    if (localtime_s(&now, &t) == 0)
    {
        return Date(now.tm_year + 1900, now.tm_mon + 1, now.tm_mday);
    }

    return Date(2025, 10, 26);
}

Date Date::addDays(int days) const
{
    Date result = *this;

    if (days >= 0)
    {
        while (days > 0)
        {
            int daysThisMonth = getDaysInMonth(*result.currentMonth, *result.currentYear);
            if (*result.currentDay + days <= daysThisMonth)
            {
                *result.currentDay += days;
            }
            else
            {
                days -= (daysThisMonth - *result.currentDay + 1);
                *result.currentDay = 1;
                if (*result.currentMonth == 12)
                {
                    *result.currentMonth = 1;
                    *result.currentYear += 1;
                }
                else
                {
                    *result.currentMonth += 1;
                }
            }
        }
    }
    else
    {
        return subtractDays(-days);
    }

    return result;
}

Date Date::subtractDays(int days) const
{
    Date result = *this;

    if (days >= 0)
    {
        while (days > 0)
        {
            if (*result.currentDay > (unsigned int)(days))
            {
                *result.currentDay -= days;
            }
            else
            {
                days -= *result.currentDay;
                if (*result.currentMonth == 1)
                {
                    *result.currentMonth = 12;
                    *result.currentYear -= 1;
                }
                else
                {
                    *result.currentMonth -= 1;
                }
                *result.currentDay = getDaysInMonth(*result.currentMonth, *result.currentYear);
            }
        }
    }
    else
    {
        return addDays(-days);
    }

    return result;
}

bool Date::operator==(const Date& other) const
{
    return *currentYear == *other.currentYear &&
        *currentMonth == *other.currentMonth &&
        *currentDay == *other.currentDay;
}

bool Date::operator!=(const Date& other) const
{
    return !(*this == other);
}

bool Date::operator<(const Date& other) const
{
    if (*currentYear != *other.currentYear)
    {
        return *currentYear < *other.currentYear;
    }
    if (*currentMonth != *other.currentMonth)
    {
        return *currentMonth < *other.currentMonth;
    }
    return *currentDay < *other.currentDay;
}

bool Date::operator>(const Date& other) const
{
    if (*currentYear != *other.currentYear)
    {
        return *currentYear > *other.currentYear;
    }
    if (*currentMonth != *other.currentMonth)
    {
        return *currentMonth > *other.currentMonth;
    }
    return *currentDay > *other.currentDay;
}

int Date::differenceInDays(const Date& other) const
{
    int days = 0;
    Date temp = *this;

    if (*this == other)
    {
        return 0;
    }
    else if (*this < other)
    {
        while (temp != other)
        {
            temp = temp.addDays(1);
            days++;
        }
    }
    else
    {
        while (temp != other)
        {
            temp = temp.subtractDays(1);
            days++;
        }
    }
    return days;
}

std::string Date::toString() const
{
    std::stringstream ss;
    ss << *currentYear << "." << std::setfill('0') << std::setw(2) << *currentMonth <<
        "." << std::setfill('0') << std::setw(2) << *currentDay;
    return ss.str();
}