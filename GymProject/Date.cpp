#include <iostream>
#include "Date.h"

Date::Date(int day, int month, int year)
{
	setDay(day);
	setMonth(month);
	setYear(year);
}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

void Date::setDay(const int day)
{
	this->day = day;
}

void Date::setMonth(const int day)
{
	this->month = month;
}

void Date::setYear(const int day)
{
	this->year = year;
}

istream& operator>>(istream& in, Date& d)
{
	cout << "Enter date:\n";
	in >> d.day >> d.month >> d.year;
	return in;
}

bool Date::operator==(const Date& other) const
{
	if (day != other.day && month != other.month && year != other.year)
		return false;

	return true;
}

void Date::show() const
{
	cout << day << "/" << month << "/" << year << "\n";
}
