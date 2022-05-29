#pragma warning(disable: 4996)
#include <iostream>
#include "Gym.h"

Gym::Gym(const int id, const char* name, const char* address, const int maxMachines, int currentMachines,
	const int maxTrainees, int currentTrainees)
{
	this->id = id;
	setName(name);
	setAddress(address);
	setMaxMachineNum(maxMachines);
	setMaxTraineeNum(maxTrainees);

	allMachines = new ExerciseMachine*[maxMachines];
	currentMachines = 0;

	allTrainees = new Trainee*[maxTrainees];
	currentTrainees = 0;
}

Gym::Gym(Gym& other) : name(NULL), address(NULL)
{
	*this = other;
}

Gym::Gym(Gym&& otherGym) : name(NULL), address(NULL)
{
	*this = std::move(otherGym);
}

Gym::~Gym()
{
	delete[]name;
	delete[]address;
}

GymLicense Gym::getLicense() const
{
	return *license;
}

int Gym::getId() const
{
	return id;
}

char* Gym::getName() const
{
	return name;
}

void Gym::setName(const char* name)
{
	this->name = strdup(name);
}

char* Gym::getAddress() const
{
	return address;
}

void Gym::setAddress(const char* address)
{
	this->address = strdup(address);
}

int Gym::getCurrentMachineNum() const
{
	return currentMachinesNum;
}

int Gym::getMaxMachineNum() const
{
	return maxMachinesNum;
}

void Gym::setCurrentMachineNum(const int machineNum)
{
	this->currentMachinesNum = machineNum;
}

void Gym::setMaxMachineNum(const int machineNum)
{
	this->maxMachinesNum = machineNum;
}

int Gym::getCurrentTraineesNum() const
{
	return currentTraineesNum;
}

int Gym::getMaxTraineeNum() const
{
	return maxTraineesNum;
}

void Gym::setCurrentTraineeNum(const int TraineeNum)
{
	this->currentTraineesNum = TraineeNum;
}

void Gym::setMaxTraineeNum(const int TraineeNum)
{
	this->maxTraineesNum = TraineeNum;
}

ExerciseMachine** Gym::getAllMachines() const
{
	return allMachines;
}

Trainee** Gym::getAllTrainees() const
{
	return allTrainees;
}

bool Gym::addTrainee(const Trainee* trainee)
{
	if (currentTraineesNum == maxTraineesNum)
		return false;

	allTrainees[currentTraineesNum] = new Trainee(*trainee);

	currentTraineesNum++;
	return true;
}

Instructor* Gym::getInstructor() const
{
	if (instructor == NULL)
		return NULL;

	return instructor;
}

void Gym::setInstructor(const Instructor* c)
{
	instructor->setName(c->getName());
	instructor->setFamilyName(c->getFamilyName());
	instructor->setPhoneNumber(c->getPhoneNumber());
	instructor->setDateOfBirth(c->getDateOfBirth());
	instructor->setFavMachine(c->getFavMachine());
	instructor->setSalary(c->getSalary());
	instructor->setNumExpYears(c->getNumExpYears());
}

bool Gym::addMachine(const ExerciseMachine* machine)
{
	if (currentMachinesNum == maxMachinesNum)
		return false;

	allMachines[currentMachinesNum] = new ExerciseMachine(*machine);

	currentMachinesNum++;
	return true;
}

void Gym::showMachines() const
{
	if (currentMachinesNum == 0)
	{
		cout << "There isn't machines in the gym\n";
		return;
	}
	cout << "Exercise machines are:\n\n";
	for (int i = 0; i < currentMachinesNum; i++)
	{
		allMachines[i]->show();
	}
}

void Gym::showTrainees() const
{
	if (currentTraineesNum == 0)
	{
		cout << "There isn't trainees in the gym\n";
		return;
	}
	cout << "Trainees are:\n\n";
	for (int i = 0; i < currentTraineesNum; i++)
	{
		allTrainees[i]->show();
	}
}

const Gym& Gym::operator=(const Gym& other)
{
	if (this != &other)
	{
		setName(other.name);
		setAddress(other.address);
		id = other.id;
		setMaxMachineNum(other.maxMachinesNum);
		setMaxTraineeNum(other.maxTraineesNum);
	}
	return *this;
}

const Gym& Gym::operator=(Gym&& other)
{
	if (this != &other)
	{
		id = other.id;
		std::swap(name, other.name);
		std::swap(address, other.address);
		maxMachinesNum = other.maxMachinesNum;
		maxTraineesNum = other.maxTraineesNum;
	}
	return *this;
}

void Gym::show() const
{
	cout << "Gym id: " << id << "name: " << name << "address: " << address << "\n";
	cout << "Instructor is: ";
	instructor->show();
	cout << endl;
	showMachines();
	cout << endl;
	showTrainees();
}