#ifndef DRIVERSLICENSERECORD_H
#define DRIVERSLICENSERECORD_H
#include <string>

class DriversLicenseRecord
{
	public:
		std::string getfirstname();
		std::string getlastname();
		int getage();
		char getvoterstatus();
		int getlicenseNum();
		void setfirstname(std::string FirstName);
		void setlastname(std::string LastName);
		void setage(int Age);
		void setvoterstatus(char status);
		void setlicenseNum(int num);

	private:
		std::string firstname;
		std::string lastname;
		int age;
		char voterstatus;
		int licenseNum;
};
#endif
