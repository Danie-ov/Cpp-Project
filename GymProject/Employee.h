#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include "Person.h";

class Employee : virtual public Person
{
private:
	double salary;

public:
	Employee(const Person& base, double salary);

	double getSalary() const;
	void setSalary(const double salary);
	void show() const;
};

#endif
