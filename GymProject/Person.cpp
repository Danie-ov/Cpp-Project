#pragma warning(disable: 4996)
#include <iostream>

using namespace std;

#include "Person.h"

int Person::numberGenerator = 0;

Person::Person(const char* name, const char* familyName, const int phoneNumber, const Date& dateOfBirth)
{
	id = ++numberGenerator;
	setName(name);
	setFamilyName(familyName);
	setPhoneNumber(phoneNumber);
	setDateOfBirth(dateOfBirth);
}

Person::Person(const Person& otherPerson) : name(NULL), familyName(NULL)
{
	*this = otherPerson;
}

Person::Person(Person&& otherPerson) : name(NULL), familyName(NULL)
{
	*this = std::move(otherPerson);
}

Person::~Person()
{
	delete[]name;
	delete[]familyName;
}

int Person::getId() const
{
	return id;
}

char* Person::getName() const
{
	return name;
}

void Person::setName(const char* name)
{
	this->name = strdup(name);
}

char* Person::getFamilyName() const
{
	return familyName;
}

void Person::setFamilyName(const char* familyName)
{
	this->familyName = strdup(familyName);
}

int Person::getPhoneNumber() const
{
	return phoneNumber;
}

void Person::setPhoneNumber(const int phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

Date Person::getDateOfBirth() const
{
	return dateOfBirth;
}

void Person::setDateOfBirth(const Date& dateOfBirth)
{
	this->dateOfBirth = dateOfBirth;
}

const Person& Person::operator++()
{
	id++;
	return *this;
}

const Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		setName(other.name);
		setFamilyName(other.familyName);
		setPhoneNumber(other.phoneNumber);
		setDateOfBirth(other.dateOfBirth);
	}
	return *this;
}

const Person& Person::operator=(Person&& other)
{
	if (this != &other)
	{
		phoneNumber = other.phoneNumber;
		std::swap(name, other.name);
		std::swap(familyName, other.familyName);
		dateOfBirth = other.dateOfBirth;
	}
	return *this;
}

void Person::show() const
{
	cout << "name: " << name << " " << familyName << ", id: " << id << ", DOB: ";
	dateOfBirth.show();
}