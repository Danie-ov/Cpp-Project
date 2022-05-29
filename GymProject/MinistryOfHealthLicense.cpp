#include <iostream>

using namespace std;

#include "MinistryOfHealthLicense.h"

MinistryOfHealthLicense::MinistryOfHealthLicense(int numOfDefibrilators)
{
	this->numOfDefibrilators = numOfDefibrilators;
}

int MinistryOfHealthLicense::getNumOfDefibrilators() const
{
	return numOfDefibrilators;
}

bool MinistryOfHealthLicense::getAllDefibrilatorsVisible() const
{
	return allDefibrilatorsVisible;
}
bool MinistryOfHealthLicense::getLicenseValid() const
{
	if(allDefibrilatorsVisible >= 2)
		return true;
	
	return false;
}