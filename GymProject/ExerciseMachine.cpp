#include <iostream>

using namespace std;

#include "ExerciseMachine.h"

const char* machineTypes[5] = { "Bicycle", "Rowing-machine", "Leg-press", "Lat-pulldown", "Chest-press" };

ExerciseMachine::ExerciseMachine(int id, eName name, double weight, int maintenancesNum, Date** maintenancesDates)
{
	this->id = id;
	this->name = name;
	this->weight = weight;
	this->maintenancesNum = maintenancesNum;
}

ExerciseMachine::ExerciseMachine(const ExerciseMachine& otherMachine) : maintenancesDates(NULL)
{
	*this = otherMachine;
}

ExerciseMachine::ExerciseMachine(ExerciseMachine&& otherMachine) : maintenancesDates(NULL)
{
	*this = std::move(otherMachine);
}

ExerciseMachine::~ExerciseMachine()
{
	for (int i = 0; i < maintenancesNum; i++)
	{
		delete maintenancesDates[i];
	}
	delete[]maintenancesDates;
}

int ExerciseMachine::getId() const
{
	return id;
}

double ExerciseMachine::getWeight() const
{
	return weight;
}

ExerciseMachine::eName ExerciseMachine::getName() const
{
	return name;
}

void ExerciseMachine::setWeight(const double weight)
{
	this->weight = weight;
}

int ExerciseMachine::getMaintenancesNum() const
{
	return maintenancesNum;
}

void ExerciseMachine::setMaintenancesNum(const int num)
{
	this->maintenancesNum = maintenancesNum;
}

Date** ExerciseMachine::getMaintenancesDates() const
{
	return maintenancesDates;
}

void ExerciseMachine::show() const
{
	cout << "Exercise machine detailes are:\n";
	cout << "id = " << id << "name = " << name << "weight = " << weight;
	cout << "maintenance dates are:\n";
	for (int i = 0; i < maintenancesNum; i++)
	{
		maintenancesDates[i]->show();
		cout << endl;
	}
}

const ExerciseMachine& ExerciseMachine::operator=(const ExerciseMachine& other)
{
	if (this != &other)
	{
		for (int i = 0; i < maintenancesNum; i++)
		{
			delete maintenancesDates[i];
		}
		delete[]maintenancesDates;
		id = other.id;
		name = other.name;
		weight = other.weight;
		maintenancesNum = other.maintenancesNum;
		maintenancesDates = new Date*[maintenancesNum];
		for (int i = 0; i < maintenancesNum; i++)
			maintenancesDates[i] = other.maintenancesDates[i];
	}
	return *this;
}