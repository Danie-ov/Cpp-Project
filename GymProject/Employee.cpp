#include <iostream>
#include "Employee.h"

Employee::Employee(const Person& base, double salary) : Person(base)
{
	setSalary(salary);
}
double Employee::getSalary() const
{
	return salary;
}

void Employee::setSalary(const double salary)
{
	this->salary = salary;
}

void Employee::show() const
{
	Person::show();
	cout << "Salary is: " << salary << "\n";
}