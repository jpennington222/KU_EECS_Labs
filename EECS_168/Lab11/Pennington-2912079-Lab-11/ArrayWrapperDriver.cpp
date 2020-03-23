#include <iostream>
#include <string>
#include <fstream>
#include "ArrayWrapper.h"
#include "ArrayWrapperDriver.h"

ArrayWrapperDriver::ArrayWrapperDriver(std::string FileName):aw{1}
{
	int size=0;
	std::ifstream inFile;
	inFile.open (FileName);
	
	if(inFile.is_open())
	{
		inFile>>size;
		if(size > 0)
		{
			try
			{
				ArrayWrapper b(size);
				aw=b;
			}
			catch(std::runtime_error& rte)
			{
				std::cout<<rte.what()<<'\n';
				std::cout<<"Array Wrapper not made\n";
			}
			for(int i=0; i<size; i++)
			{
				double newValue;
				inFile>>newValue;
				aw.setEntry(i, newValue);
				
			}
		}
		inFile.close();
	}
	else
	{
		std::cout<<"Something is wrong with the file\n";
	}
}

void ArrayWrapperDriver::run()
{
	int choice = 0;
	bool set = false;
	bool get = false;

	while(choice != 1)
	{
		std::cout<<"1) Exit\n";
		std::cout<<"2) Set Value\n";
		std::cout<<"3) Get Value\n";
		std::cout<<"4) Test Copy Constructor\n";
		std::cout<<"5) Test Assignment\n";
		std::cout<<"6) Print\n";
		std::cout<<"Enter your choice: ";
		std::cin>>choice;

		if(choice == 2)
		{
			std::cout<<'\n';

			double nVal;
			int ind = 0;

			std::cout<<"Enter new value: ";
			std::cin>>nVal;
			while(set == false)
			{
				std::cout<<"Enter index to place the new value: ";
				std::cin>>ind;
				try
				{
					aw.setEntry(ind, nVal);
					set = true;
				}
				catch(std::runtime_error& rte)
				{
					std::cout<<rte.what()<<'\n';
				}
			}
			std::cout<<'\n';
		}

		else if(choice == 3)
		{
			std::cout<<'\n';

			int ind1 = 0;

			while(get == false)
			{
				std::cout<<"Enter index: ";
				std::cin>>ind1;
				try
				{
					std::cout<<"Value at index "<<ind1<<" = "<<aw.getEntry(ind1)<<"\n";
					get = true;
				}
				catch(std::runtime_error& rte)
				{
					std::cout<<rte.what()<<'\n';
				}
			}
			std::cout<<'\n';
		}

		else if(choice == 4)
		{
			testCopyConstructor(aw);
			std::cout<<'\n';
			std::cout<<'\n';
		}

		else if(choice == 5)
		{
			std::cout<<'\n';
			testAssignment();
			std::cout<<'\n';
		}

		else if(choice == 6)
		{
			std::cout<<'\n';
			int arrSize = aw.getSize();
			for(int i=0; i<arrSize; i++)
			{
				std::cout<<aw.getEntry(i);
				if(i != arrSize-1)
				{
					std::cout<<", ";
				}
			}
			std::cout<<'\n';
			std::cout<<'\n';
		}

		else if(choice != 1)
		{
			std::cout<<'\n';
			std::cout<<"Please input a number between 1 and 6\n";
			std::cout<<'\n';
		}
	}
	std::cout<<'\n';
	std::cout<<"Goodbye\n";
	std::cout<<'\n';
}

void ArrayWrapperDriver::testCopyConstructor(ArrayWrapper aw)const
{
	ArrayWrapper copyOfAw(aw);

	copyOfAw.setEntry(0,-1);
	copyOfAw.setEntry(copyOfAw.getSize()-1,-1);
	std::cout<<'\n';
	for(int i=0; i<copyOfAw.getSize(); i++)
	{
		std::cout<<copyOfAw.getEntry(i);
		if(i != copyOfAw.getSize()-1)
		{
			std::cout<<" ,";
		}
	}
}

void ArrayWrapperDriver::testAssignment()
{
	int arr_size = 0;
	bool valid = false;

	while(valid == false)
	{	
		std::cout<<"Input the size of the array: ";
		std::cin>>arr_size;
		try
		{
			ArrayWrapper newAw(arr_size);
			for(int i=0; i<arr_size; i++)
			{
				double value;
				std::cout<<"Please enter value for index "<<i<<": ";
				std::cin>>value;
				newAw.setEntry(i,value);
			}
			aw=newAw;
			valid = true;	
		}
		catch(std::runtime_error& rte)
		{
			std::cout<<rte.what()<<'\n';
		}
	}
}




	
		





































