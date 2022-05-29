#ifndef _PERSON_H
#define _PERSON_H

#include "Date.h"
class Date;

class Person
{
private:
	int id;
	static int numberGenerator;
	char* name;
	char* familyName;
	int phoneNumber;
	Date dateOfBirth;

public:
	Person(const char* name, const char* familyName, const int phoneNumber, const Date& dateOfBirth);
	Person(const Person& otherPerson);
	Person(Person&& otherPerson);												
	~Person();																	

	int getId() const;
	char* getName() const;
	char* getFamilyName() const;
	int  getPhoneNumber() const;
	Date getDateOfBirth() const;
	void setName(const char* name);
	void setFamilyName(const char* familyName);
	void setPhoneNumber(const int phoneNumber);
	void setDateOfBirth(const Date& dateOfBirth);

	const Person& operator++(); 
	const Person& operator=(const Person& other);
	const Person& operator=(Person&& other);

	void show() const;
};


#endif

