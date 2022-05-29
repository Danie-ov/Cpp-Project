#ifndef _FIREDEPARTMENTLICENSE_H
#define _FIREDEPARTMENTLICENSE_H

class FireDepartmentLicense
{
private:
	int numOfEmergencySigns;
	bool allSignsVisible;

public:
	FireDepartmentLicense(int numOfEmergencySigns);
	int getNumOfSigns()  const;
	bool getAllSignsVisible() const;
	bool getLicenseValid() const;
};

#endif
