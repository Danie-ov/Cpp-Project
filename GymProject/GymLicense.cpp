#include <iostream>
#include "GymLicense.h"

int GymLicense::numberGenerator = 0;

GymLicense::GymLicense(MinistryOfHealthLicense& mLicense, FireDepartmentLicense& fLicense)
{
	id = ++numberGenerator;
	this->mLicense = &mLicense;
	this->fLicense = &fLicense;
}

int GymLicense::getId() const
{
	return id;
}

bool GymLicense::getIsValid() const
{
	return isValid;
}

void GymLicense::setIsValid(const bool status)
{
	this->isValid = status;
}

ostream& operator<<(ostream& os, const GymLicense& gymLicense)
{
	return os;
}