#include <iostream>
#include <string>
#include "DriversLicenseRecord.h"

std::string DriversLicenseRecord::getfirstname()
{
	return firstname;
}

std::string DriversLicenseRecord::getlastname()
{
	return lastname;
}

int DriversLicenseRecord::getage()
{
	return age;
}

char DriversLicenseRecord::getvoterstatus()
{
	return voterstatus;
}

int DriversLicenseRecord::getlicenseNum()
{
	return licenseNum;
}

void DriversLicenseRecord::setfirstname(std::string FirstName)
{
	firstname = FirstName;
}

void DriversLicenseRecord::setlastname(std::string LastName)
{
	lastname = LastName;
}

void DriversLicenseRecord::setage(int Age)
{
	age = Age;
}

void DriversLicenseRecord::setvoterstatus(char status)
{
	voterstatus = status;
}

void DriversLicenseRecord::setlicenseNum(int num)
{
	licenseNum = num;
}
