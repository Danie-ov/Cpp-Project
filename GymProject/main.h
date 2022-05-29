#ifndef __MAIN__H
#define __MAIN__H

#include "Instructor.h"
#include "Employee.h"
#include "ExerciseMachine.h"
#include "FireDepartmentLicense.h"
#include "Gym.h"
#include "GymLicense.h"
#include "MinistryOfHealthLicense.h"
#include "Person.h"
#include "Trainee.h"
#include "Date.h"

enum eMenuOptions
{
	eSetMaxTraineesGym, eAddTrainee, eAddInstructor, eAddMachineExercise, ePrintTrainees,
	ePrintLicense, ePrintExerciseMachine, ePrintGym, eNofOptions
};

static const int MAX_LEN = 255;

const char* options[eNofOptions] = { "Change max number of trainees in a gym", "Add a trainee",
"Add a constructor", "Add an exercise machine", "Show all trainees", "Show license validation",
"Show all exercise machines", "Show gym info" };

int menu();
int initMaxNumOfTrainees();
Gym* initGym();
Trainee* initTrainee();
Employee* initEmployee();
int pickFavoriteMachine();
ExerciseMachine* initMachine();
Date* initDate();
Instructor* initInstructor();


#endif // !__MAIN__H