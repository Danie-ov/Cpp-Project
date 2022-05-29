#ifndef _MINISTRYOFHEALTHLICENSE_H
#define _MINISTRYOFHEALTHLICENSE_H

class MinistryOfHealthLicense
{
private:
	int numOfDefibrilators;
	bool allDefibrilatorsVisible;

public:
	MinistryOfHealthLicense(int numOfDefibrilators);
	int getNumOfDefibrilators() const;
	bool getAllDefibrilatorsVisible() const;
	bool getLicenseValid() const;

};

#endif
