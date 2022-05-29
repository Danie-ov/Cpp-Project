#ifndef _EXERCISEMACHINE_H
#define _EXERCISEMACHINE_H

#include "Date.h";

class ExerciseMachine
{
public:
	enum eName { BICYCLE, ROWING_MACHINE, LEG_PRESS, LAT_PULLDOWN, CHEST_PRESS };

private:
	int id;
	eName name;
	double weight;
	int maintenancesNum;
	Date** maintenancesDates;

public:
	ExerciseMachine(int id, eName name, double weight, int maintenancesNum, Date** maintenancesDates);	//constructor
	ExerciseMachine(const ExerciseMachine& otherMachine);												//copy constructor
	ExerciseMachine(ExerciseMachine&& otherMachine);													//move constructor
	~ExerciseMachine();																					//destructor

	int getId() const;
	eName getName() const;
	double getWeight() const;
	int getMaintenancesNum() const;
	Date** getMaintenancesDates() const;
	void setWeight(const double weight);
	void setMaintenancesNum(const int num);
	void show() const;
	const ExerciseMachine& operator=(const ExerciseMachine& other);
};



#endif
