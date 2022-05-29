#include <iostream>
#include "Instructor.h"

Instructor::Instructor(const Trainee& trainee, const Employee& employee, int numExpYears) : 
	Person(trainee.getName(), trainee.getFamilyName(), trainee.getPhoneNumber(), trainee.getDateOfBirth()),
	Trainee(trainee), Employee(employee)
{
	setNumExpYears(numExpYears);
}

int Instructor::getNumExpYears() const
{
	return numExpYears;
}

void Instructor::setNumExpYears(const int num)
{
	this->numExpYears = num;
}

void Instructor::show() const
{
	Trainee::show();
	Employee::show();
	cout << "Number of experience is: " << numExpYears << "\n";
}