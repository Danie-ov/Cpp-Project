#ifndef _TRAINEE_H
#define _TRAINEE_H

#include "ExerciseMachine.h"
#include "Person.h"
class Date;

class Trainee : virtual public Person
{
private:
	int favoriteMachine;

public:
	Trainee(const Person& base, int favoriteMachine);

	int getFavMachine() const;
	void setFavMachine(int machine);
	void show() const;
};

#endif
