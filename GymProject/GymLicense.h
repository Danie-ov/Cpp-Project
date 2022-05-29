#ifndef _GYMLICENSE_H
#define _GYMLICENSE_H

#include <iostream>

class FireDepartmentLicense;
class MinistryOfHealthLicense;

using namespace std;

class GymLicense
{
private:
	int id;
	static int numberGenerator;
	MinistryOfHealthLicense* mLicense;
	FireDepartmentLicense* fLicense;
	bool isValid;

public:
	GymLicense(MinistryOfHealthLicense& mLicense, FireDepartmentLicense& fLicense);
	int getId() const;
	bool getIsValid() const;
	void setIsValid(const bool status);

	friend ostream& operator<<(ostream& os, const GymLicense& gymLicense);
};



#endif
