#ifndef DMV_H
#define DMV_H
#include "DriversLicenseRecord.h"
#include <string>
#include <iostream>

class DMV
{
	public:
		DMV(std::string FileName);
		void run();

	private:
		DriversLicenseRecord* record;
		DriversLicenseRecord* recordcopy;
		int recordsize;
};
#endif
	



