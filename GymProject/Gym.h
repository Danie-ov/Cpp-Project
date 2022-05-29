#ifndef _GYM_H
#define _GYM_H

#include "GymLicense.h"
#include "ExerciseMachine.h"
#include "Trainee.h"
#include "Instructor.h"

class Gym
{
private:
	int id;
	char* name;
	char* address;
	int maxMachinesNum;
	int currentMachinesNum;
	int maxTraineesNum;
	int currentTraineesNum;
	ExerciseMachine** allMachines;
	Trainee** allTrainees;
	GymLicense* license;
	Instructor* instructor;

public:
	Gym(const int id, const char* name, const char* address, const int maxMachines, 
		int currentMachines, const int maxTrainees, int currentTrainees);
	Gym(Gym& gym);																
	Gym(Gym&& otherGym);														
	~Gym();																		

	GymLicense getLicense() const;
	int getId() const;
	char* getAddress() const;
	char* getName() const;
	int getCurrentMachineNum() const;
	int getMaxMachineNum() const;
	int getCurrentTraineesNum() const;
	int getMaxTraineeNum() const;
	void setAddress(const char* address);
	void setName(const char* name);
	void setCurrentMachineNum(const int machineNum);
	void setMaxMachineNum(const int machineNum);
	void setCurrentTraineeNum(const int TraineeNum);
	void setMaxTraineeNum(const int TraineeNum);
	ExerciseMachine** getAllMachines() const;
	Trainee** getAllTrainees() const;
	bool addTrainee(const Trainee* trainee);
	Instructor* getInstructor() const;
	bool addMachine(const ExerciseMachine* machine);
	void setInstructor(const Instructor* constructor);
	void showMachines() const;
	void showTrainees() const;
	void show() const;

	const Gym& operator=(const Gym& other);
	const Gym& operator=(Gym&& other);

};

#endif
