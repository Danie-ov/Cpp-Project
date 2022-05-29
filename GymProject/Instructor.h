#ifndef _INSTRUCTOR_H
#define _INSTRUCTOR_H

#include "Employee.h";
#include "Trainee.h";

class Instructor : public Trainee, public Employee
{
private:
	int numExpYears;

public:
	Instructor(const Trainee& trainee, const Employee& employee, int numExpYears);

	int getNumExpYears() const;
	void setNumExpYears(const int num);
	void show() const;
};

#endif
