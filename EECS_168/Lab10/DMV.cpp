#include "DMV.h"
#include "DriversLicenseRecord.h"
#include <iostream>
#include <fstream>
#include <string>

DMV::DMV(std::string FileName)
{
	std::string FN;
	std::string LN;
	int AGE;
	char VS;
	int LisNum;
	int size = 0;

	std::ifstream inFile;
	inFile.open (FileName);
	inFile>>size;
	recordsize = size;
	record = new DriversLicenseRecord[recordsize];
	recordcopy = new DriversLicenseRecord[recordsize];

	for(int i=0; i<size; i++)
	{
		inFile>>FN;
		record[i].setfirstname(FN);
		recordcopy[i].setfirstname(FN);
		inFile>>LN;
		record[i].setlastname(LN);
		recordcopy[i].setlastname(LN);
		inFile>>AGE;
		record[i].setage(AGE);
		recordcopy[i].setage(AGE);
		inFile>>VS;
		record[i].setvoterstatus(VS);
		recordcopy[i].setvoterstatus(VS);
		inFile>>LisNum;
		record[i].setlicenseNum(LisNum);
		recordcopy[i].setlicenseNum(LisNum);
	}
	inFile.close();
}



void DMV::run()
{
	int choice = 0;
	int firstage = 0;
	int lastage = 0;
	int driver = 0;
	int max = 0;
	int count = 0;
	std::string fn;
	std::string ln;
	int a;
	char stat;
	int number;
	int ycount = 0;

	for(int i=0; i<recordsize; i++)
	{
		for(int j=i+1; j<recordsize; j++)
		{
			if(recordcopy[j].getage() < recordcopy[i].getage())
			{		
				//change first name
				fn=recordcopy[j].getfirstname();
				recordcopy[j].setfirstname(recordcopy[i].getfirstname());
				recordcopy[i].setfirstname(fn);

				//change last name
				ln = recordcopy[j].getlastname();
				recordcopy[j].setlastname(recordcopy[i].getlastname());
				recordcopy[i].setlastname(ln);

				//change age
				a = recordcopy[j].getage();
				recordcopy[j].setage(recordcopy[i].getage());
				recordcopy[i].setage(a);

				//change voter status
				stat = recordcopy[j].getvoterstatus();
				recordcopy[j].setvoterstatus(recordcopy[i].getvoterstatus());
				recordcopy[i].setvoterstatus(stat);

				//change license number
				number = recordcopy[j].getlicenseNum();
				recordcopy[j].setlicenseNum(recordcopy[i].getlicenseNum());
				recordcopy[i].setlicenseNum(number);
			}
		}
	}

	while(choice != 6)
	{
		std::cout<<"Select an option: \n";
		std::cout<<"1) Print all Driver Info\n";
		std::cout<<"2) Print all voters\n";
		std::cout<<"3) Print specific driver\n";
		std::cout<<"4) Create registered voter file\n";
		std::cout<<"5) Print in ascending order in age range\n";
		std::cout<<"6) Quit\n";
		std::cout<<"Enter your choice: ";
		std::cin>>choice;

		if(choice == 1)
		{
			std::cout<<'\n';
			for(int i=0; i<recordsize; i++)
			{
				std::cout<<record[i].getlastname()<<", "<<record[i].getfirstname()<<" ("<<record[i].getage()<<"): "<<record[i].getlicenseNum()<<'\n';
			}
			std::cout<<'\n';
		}

		else if(choice == 2)
		{
			std::cout<<'\n';
			for(int i=0; i<recordsize; i++)
			{
				if(record[i].getvoterstatus() == 'Y')
				{
					std::cout<<record[i].getlastname()<<", "<<record[i].getfirstname()<<" ("<<record[i].getage()<<"): "<<record[i].getlicenseNum()<<'\n';
				}
			}
			std::cout<<'\n';
		}

		else if(choice == 3)
		{	count = 0;
			std::cout<<'\n';
			std::cout<<"Input drivers license number: ";
			std::cin>>driver;
			for(int i=0; i<recordsize; i++)
			{
				if(record[i].getlicenseNum() == driver)
				{
					std::cout<<record[i].getlastname()<<", "<<record[i].getfirstname()<<" ("<<record[i].getage()<<"): "<<record[i].getlicenseNum()<<'\n';
					count++;
				}
			}
			if(count == 0)
			{
				std::cout<<"No record found\n";
				count = 0;
			}
			std::cout<<'\n';
		}

		else if(choice == 4)
		{	
			std::cout<<'\n';
			std::string allResultsforFile;
			std::string outFileName;

			std::cout<<"Enter Filename: ";
			std::cin>>outFileName;
			for(int i=0; i<recordsize; i++)
			{
				if(record[i].getvoterstatus() == 'Y')
				{
					ycount++;
				}
			}

			std::ofstream myfile;
			myfile.open(outFileName);
			myfile<<ycount<<'\n';
			for(int i=0; i<recordsize; i++)
			{
				if(record[i].getvoterstatus() == 'Y')
				{
					myfile<<record[i].getfirstname()<<" "<<record[i].getlastname()<<" "<<record[i].getage()<<" "<<record[i].getlicenseNum()<<'\n';
				}
			}
			myfile.close();
			std::cout<<'\n';
		}

		else if(choice == 5)
		{
			std::cout<<'\n';
			for(int i=0; i<recordsize; i++)
			{
				if(record[i].getage() > max)
				{
					max = record[i].getage();
				}
			}
			
			while(1)
			{
				std::cout<<"Input first age for the age range: ";
				std::cin>>firstage;
				if(firstage < 0 || firstage>max)
				{
					std::cout<<"Please input an age 0 or greater and less than or equal to the maximum age\n";
				}
				else if(firstage >= 0)
				{
					break;
				}
			}
			while(1)
			{
				std::cout<<"Input second age for the age range: ";
				std::cin>>lastage;
				if(lastage < firstage || lastage>max)
				{
					std::cout<<"Please input an age greater than the first age and less than or equal to the maximum age\n";
				}
				else if(lastage >= firstage && lastage <= max)
				{
					break;
				}
			}
			std::cout<<'\n';
			for(int i=0; i<recordsize; i++)
			{
				if(recordcopy[i].getage() >= firstage && recordcopy[i].getage() <= lastage)
				{
				std::cout<<recordcopy[i].getfirstname()<<" "<<recordcopy[i].getlastname()<<" "<<recordcopy[i].getage()<<" "<<recordcopy[i].getlicenseNum()<<'\n';
				}
			}
			std::cout<<'\n';
		}
		else
		{
			std::cout<<"please input a number between 1 and 6\n";
		}
	}
	std::cout<<"Goodbye\n";
	delete[] record;
	delete[] recordcopy;
}


	
