#pragma warning(disable: 4996)
#include <iostream>
#include "main.h"

using namespace std;

int main()
{
	int option;
	int stop = 0;

	Gym* gym = initGym();
	Trainee* trainee = NULL;
	ExerciseMachine* machine = NULL;
	Instructor* instructor = NULL;

	do
	{
		option = menu();
		switch (option)
		{
		case eSetMaxTraineesGym:
		{
			int num = initMaxNumOfTrainees();
			gym->setMaxTraineeNum(num);
			break;
		}

		case eAddTrainee:
		{
			trainee = initTrainee();
			gym->addTrainee(trainee);
			break;
		}

		case eAddInstructor:
		{
			if (gym->getInstructor() == NULL)
			{
				instructor = initInstructor();
				gym->setInstructor(instructor);
			}
			else
				cout << "The Gym has already constructor\n";
			break;
		}

		case eAddMachineExercise:
		{
			machine = initMachine();
			gym->addMachine(machine);
			break;
		}

		case ePrintTrainees:
		{
			gym->showTrainees();
			break;
		}

		case ePrintLicense:
		{
			if (gym->getLicense().getIsValid())
				cout << "License is valid" << endl;
			else
				cout << "License is invalid" << endl;
			break;
		}

		case ePrintExerciseMachine:
		{
			gym->showMachines();
			break;
		}

		case ePrintGym:
		{
			gym->show();
			break;
		}

		case -1:
		{
			printf("Bye bye\n");
			stop = 1;
			break;
		}

		default:
			printf("Wrong choice\n");
			break;
		}
	} while (!stop);

	return 0;
}


int menu()
{
	int option;
	printf("\n\n");
	printf("Please choose one of the following options\n");
	for (int i = 0; i < eNofOptions; i++)
		cout << i << "-" << options[i] << "\n";
	cout << "-1 -" << "Quit\n";
	cin >> option;
	return option;
}

Gym* initGym()
{
	/*int id, maxMachines, maxTrainees;
	char name[MAX_LEN], address[MAX_LEN];

	cout << "Enter Gym name:\n";
	cin >> name;

	cout << "Enter Gym address:\n";
	cin >> address;

	cout << "Enter Gym id:\n";
	cin >> id;

	cout << "Enter number of max machines:\n";
	cin >> maxMachines;

	cout << "Enter number of max trainees:\n";
	cin >> maxTrainees;

	return new Gym(id, name, address, maxMachines, 0, maxTrainees, 0);*/
	return new Gym(12345, "Crossfit", "Balaban", 6, 0, 15, 0);
}

int initMaxNumOfTrainees()
{
	int num;
	cout << "Enter new max num" << endl;
	cin >> num;

	return num;
}

Trainee* initTrainee()
{
	char name[MAX_LEN], lastName[MAX_LEN]; 
	int phoneNumber, favorite;

	cout << "Enter name:\n";
	cin >> name;

	cout << "Enter last name:\n";
	cin >> lastName;

	cout << "Enter phone number:\n";
	cin >> phoneNumber;

	Date* dateOfBirth = initDate();
	favorite = pickFavoriteMachine();

	return new Trainee(Person(name, lastName, phoneNumber, *dateOfBirth), (ExerciseMachine::eName)favorite);
}

Employee* initEmployee()
{
	char name[MAX_LEN], lastName[MAX_LEN];
	int phoneNumber;
	double salary;

	cout << "Enter name:\n";
	cin >> name;

	cout << "Enter last name:\n";
	cin >> lastName;

	cout << "Enter phone number:\n";
	cin >> phoneNumber;

	cout << "Enter salary:\n";
	cin >> salary;

	Date* dateOfBirth = initDate();

	return new Employee(Person(name, lastName, phoneNumber, *dateOfBirth), salary);
}

int pickFavoriteMachine()
{
	int fav;
	cout << "Enter favorite type machine\n0-Bicycle, 1- Rowing-machine, 2-Leg-press, 3-Lat-pulldown, 4-Chest-press\n";
	cin >> fav;
	return fav;
}

ExerciseMachine* initMachine()
{
	int type, id, maintenancesNum;
	double weight;

	type = pickFavoriteMachine();

	cout << "Enter id:\n";
	cin >> id;

	cout << "Enter weight:\n";
	cin >> weight;

	cout << "Enter number of maintenance:\n";
	cin >> maintenancesNum;

	Date** arr = new Date*[maintenancesNum];
	for (int i = 0; i < maintenancesNum; i++)
	{
		cout << "Add maintenance date:\n";
		arr[i] = initDate();
	}
	
	return new ExerciseMachine(id, (ExerciseMachine::eName)type, weight, maintenancesNum, arr);
}

Date* initDate()
{
	int day, month, year;
	cout << "Enter Date of birth:\n";

	cout << "Enter day:\n";
	cin >> day;

	cout << "Enter month:\n";
	cin >> month;

	cout << "Enter year:\n";
	cin >> year;

	return new Date(day, month, year);
}

Instructor* initInstructor()
{
	Trainee* t = initTrainee();

	double salary;
	cout << "Enter salary:\n";
	cin >> salary;

	char name[MAX_LEN], lastName[MAX_LEN]; ////////////check with keren
	int phoneNumber = t->getPhoneNumber();
	Date d = t->getDateOfBirth();

	strcpy(name, t->getName());
	strcpy(lastName, t->getFamilyName());

	Employee* e = new Employee(Person(name ,lastName, phoneNumber, d), salary);

	int numOfExp;
	cout << "Enter number of experience:\n";
	cin >> numOfExp;

	return new Instructor(*t, *e, numOfExp);
}

