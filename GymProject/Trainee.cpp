#pragma warning(disable: 4996)

#include <iostream>
#include "Trainee.h"


Trainee::Trainee(const Person& base, int favoriteMachine) : Person(base)
{
	setFavMachine(favoriteMachine);
}

int Trainee::getFavMachine() const
{
	return favoriteMachine;
}

void Trainee::setFavMachine(int machine)
{
	this->favoriteMachine = machine;
}

void Trainee::show() const
{
	Person::show();
	cout << "his favorite machine: " << ExerciseMachine::eName(favoriteMachine) << "\n";
}