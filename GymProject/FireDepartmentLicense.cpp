#include <iostream>

using namespace std;

#include "FireDepartmentLicense.h"

FireDepartmentLicense::FireDepartmentLicense(int numOfEmergencySigns)
{
	this->numOfEmergencySigns = numOfEmergencySigns;
}

int FireDepartmentLicense::getNumOfSigns() const
{
	return numOfEmergencySigns;
}
bool FireDepartmentLicense::getAllSignsVisible() const
{
	return allSignsVisible;
}

bool FireDepartmentLicense::getLicenseValid() const
{
	if(allSignsVisible >= 5)
		return true;
	return false;
}