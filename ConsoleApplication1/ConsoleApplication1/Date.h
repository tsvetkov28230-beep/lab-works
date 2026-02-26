#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <sstream>

class Date
{
private:
	unsigned int* currentYear, * currentMonth, * currentDay;
	int getDaysInMonth(int month, int year) const;
	bool checkLeapYear(int year) const;

public:
	Date();
	Date(unsigned int year_, unsigned int month_, unsigned int day_);
	Date(const Date& other);
	Date(const std::string& dateString);
	Date& operator=(const Date& other);
	~Date();

	unsigned int getCurrentYear();
	unsigned int getCurrentMonth();
	unsigned int getCurrentDay();

	void setCurrentYear(unsigned int year_);
	void setCurrentMonth(unsigned int month_);
	void setCurrentDay(unsigned int day_);

	static Date getCurrentDate();

	Date addDays(int days) const;
	Date subtractDays(int days) const;

	bool operator==(const Date& other) const;
	bool operator!=(const Date& other) const;
	bool operator<(const Date& other) const;
	bool operator>(const Date& other) const;

	int differenceInDays(const Date& other) const;

	std::string toString() const;

};
