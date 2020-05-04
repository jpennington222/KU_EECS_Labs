/*
 * @Author: Joseph Pennington
 * @File Name: Executive.cpp
 * @Assignment: EECS 560 Lab 07
 * @Brief: This program is the Executive.cpp file for the lab. It passes the inFile contents to the respective functions.
 */

#include "Executive.h"
#include <iostream>
#include <fstream>
#include <string>
#include "BSTEntry.h"

using namespace std;

Executive::Executive(std::string Filename, std::string Filename2)
{
	file1 = Filename;
	file2 = Filename2;

	myMaxHeap.buildHeap(file1);
	myMinHeap.buildHeap(file2);
}

void Executive::run()
{
	string choice = "0";
	while(choice != "3")
	{
		cout << "Choose one operation from the options below:\n";
		cout << "1- Patient Management\n"; //max heap
		cout << "2- Doctor Assignment\n"; //min heap
		cout << "3- Exit\n";

		cin >> choice;
		cout << '\n';

		//Patient
		if(choice == "1")
		{
			maxMenu();
			//break;
		}

		//Doctor
		else if(choice == "2")
		{
			minMenu();
			//break;
		}

		//Exit
		else if(choice == "3")
		{
			cout << "Bye Bye!\n";
		}

		//Bad Input
		else
		{
			cout << "Please enter a number between 1 and 9.\n";
			cout << '\n';
		}
	}
}

//Patients
void Executive::maxMenu()
{
	string choice = "0";
	while(choice != "9")
	{
		cout << "-----------Patient Management System-------------\n";
		cout << "1- New Patient\n";
		cout << "2- Treat Patient\n";
		cout << "3- Change Urgency\n";
		cout << "4- Next Patient\n";
		cout << "5- Last Patient\n";
		cout << "6- Patient Token\n";
		cout << "7- Patient Count\n";
		cout << "8- Patient Report\n";
		cout << "9- Go Back to Menu\n";

		cin >> choice;
		cout << '\n';

		//New Patient (Insert)
		if(choice == "1")
		{
			string tempFirst;
			string tempLast;
			int tempKey;

			cout << "Enter Patient First Name: ";
			cin >> tempFirst;
			cout << "Enter Patient Last Name: ";
			cin >> tempLast;
			cout << "Enter Patient Priority: ";
			cin >> tempKey;

			BSTEntry bste(tempFirst, tempLast, tempKey);
			myMaxHeap.insert(bste);
			if(myMaxHeap.getAdded() == true)
			{
				myMaxHeap.heapify();
				cout << "New Patient Record Added\n";
			}
			cout << '\n';
		}

		//Treat Patient (Delete Highest)
		else if(choice == "2")
		{
			if(myMaxHeap.deleteMax() == false)
			{
				cout << "Empty Heap\n";
			}
			cout << '\n';
		}

		//Change Urgency
		else if(choice == "3") //fix this
		{
			if(myMaxHeap.getItemCount() == 0)
			{
				cout << "Empty Heap\n";
			}

			else
			{
				string tempFirst;
				string tempLast;
				int tempKey;

				cout << "Enter patient details to change urgency:\n";
				cout << "Enter Patient First Name: ";
				cin >> tempFirst;
				cout << "Enter Patient Last Name: ";
				cin >> tempLast;
				if(myMaxHeap.current(tempFirst, tempLast))
				{
					cout << "Enter new urgency level: ";
					cin >> tempKey;
					BSTEntry bste(tempFirst, tempLast, tempKey);
					myMaxHeap.deleteEntry(bste);
					myMaxHeap.heapify();
					cout << "The patient record is updated\n";
				}
				else
				{
					cout << "Record not found\n";
				}
			}
			cout << '\n';
		}

		//Next Patient (Highest Priority)
		else if(choice == "4")
		{
			if(myMaxHeap.getItemCount() == 0)
			{
				cout << "Empty Heap\n";
			}
			else
			{
				myMaxHeap.findMax();
				cout << '\n';
			}
		}

		//Last Patient (Lowest Priority)
		else if(choice == "5")
		{
			if(myMaxHeap.getItemCount() == 0)
			{
				cout << "Empty Heap\n";
			}
			else
			{
				myMaxHeap.findMin();
				cout << '\n';
			}
		}

		//Patient Token (Position in Heap)
		else if(choice == "6") //may be wrong
		{
			if(myMaxHeap.getItemCount() == 0)
			{
				cout << "Empty Heap\n";
			}
			else
			{
				string tempFirst;
				string tempLast;
				int pos = 0;

				cout << "Enter Patient First Name: ";
				cin >> tempFirst;
				cout << "Enter Patient Last Name: ";
				cin >> tempLast;

				pos = myMaxHeap.position(tempFirst, tempLast);
				if(pos == -1)
				{
					cout << "Entry Not Found\n";
				}
				else
				{
					cout << "Patient Token: " << pos+1 << '\n';
				}
			}
			cout << '\n';
		}

		//Patient Count (Total count)
		else if(choice == "7")
		{
			cout << "Current patient count is: ";
			cout << myMaxHeap.getItemCount() << '\n';
			cout << '\n';
		}

		//Patient Report (Level order print)
		else if(choice == "8")
		{
			if(myMaxHeap.getItemCount() == 0)
			{
				cout << "Empty Heap\n";
			}
			else
			{
				myMaxHeap.levelOrder();
				cout << '\n';
			}
		}

		//Exit
		else if(choice == "9")
		{
			return;
		}
	}
}

//Doctors
void Executive::minMenu()
{
	string choice = "0";
	while(choice != "10")
	{
		cout << "-----------Doctor Management System-------------\n";
		cout << "1- New Doctor\n";
		cout << "2- Update Patients\n";
		cout << "3- Remove Doctor\n";
		cout << "4- Next Available Doctor\n";
		cout << "5- Check Availability\n";
		cout << "6- Total Doctor Count\n";
		cout << "7- Available Doctor Count\n";
		cout << "8- Available Doctor Report\n";
		cout << "9- Busy Doctors List\n";
		cout << "10- Go Back to Menu\n";

		cin >> choice;
		cout << '\n';

		//New Doctor (Insert)
		if(choice == "1")
		{
			string tempFirst;
			string tempLast;
			int tempKey = 0;

			cout << "Enter Doctor First Name: ";
			cin >> tempFirst;
			cout << "Enter Doctor Last Name: ";
			cin >> tempLast;

			BSTEntry bste(tempFirst, tempLast, tempKey);
			myMinHeap.insert(bste);
			if(myMinHeap.getAdded() == true)
			{
				myMinHeap.heapify();
				cout << "New Doctor is added and available\n";
			}
			cout << '\n';
		}

		//Update Patients (Change Patient Count)
		else if(choice == "2")
		{
			if(myMinHeap.getItemCount() == 0)
			{
				cout << "Empty Heap\n";
			}

			else
			{
				string tempFirst;
				string tempLast;

				cout << "Enter doctor details to update the patient count:\n";
				cout << "Enter Doctor First Name: ";
				cin >> tempFirst;
				cout << "Enter Doctor Last Name: ";
				cin >> tempLast;

				int patientCount = myMinHeap.current(tempFirst, tempLast);
				if(patientCount != -1)
				{
					int select = 0;
					cout << "Select 1 to add patients or 0 to reduce patients: ";
					cin >> select;
					if(select == 0)
					{
						int reduce = 0;
						cout << "Enter how many patients to remove: ";
						cin >> reduce;
						patientCount = patientCount - reduce;

						if(patientCount < 0)
						{
							cout << "Invalid number of patients to reduce\n";
						}
						else
						{
							BSTEntry bste(tempFirst, tempLast, patientCount);
							myMinHeap.deleteEntry(bste);
							myMinHeap.heapify();
							cout << "The doctor's record is updated\n";
						}
					}

					else if(select == 1)
					{
						int add = 0;
						cout << "Enter how many patients to add: ";
						cin >> add;
						patientCount = patientCount + add;

						if(patientCount > 25)
						{
							cout << "Invalid number of patients to add\n";
						}
						else
						{
							BSTEntry bste(tempFirst, tempLast, patientCount);
							myMinHeap.deleteEntry(bste);
							myMinHeap.heapify();
							cout << "The doctor's record is updated\n";
						}

					}
					else
					{
						cout << "Invalid Input\n";
					}
					cout << '\n';
				}
			}
		}

		//Remove Doctor (Delete Highest)
		else if(choice == "3")
		{
			if(myMinHeap.deleteMin() == false)
			{
				cout << "Empty Heap\n";
			}
			cout << '\n';
		}

		//Next Available Doctor (Highest Priority)
		else if(choice == "4")
		{
			if(myMinHeap.getItemCount() == 0)
			{
				cout << "Empty Heap\n";
			}
			else
			{
				myMinHeap.findMin();
				cout << '\n';
			}
		}

		//Check Availability (Check a doctor)
		else if(choice == "5")
		{
			if(myMinHeap.getItemCount() == 0)
			{
				cout << "Empty Heap\n";
			}
			else
			{
				string tempFirst;
				string tempLast;

				cout << "Check Available\n";
				cout << "Enter Doctor First Name: ";
				cin >> tempFirst;
				cout << "Enter Doctor Last Name: ";
				cin >> tempLast;
				if(myMinHeap.checkDoctor(tempFirst, tempLast) == true)
				{
					cout << "This doctor is available\n";
				}
				else
				{
					cout << "This doctor is not available\n";
				}
				cout << '\n';
			}
		}

		//Total Doctor Count (Total count)
		else if(choice == "6")
		{
			cout << "Current doctor count is: ";
			cout << myMinHeap.getItemCount() << '\n';
			cout << '\n';
		}

		//Available Doctor Count (Available count)
		else if(choice == "7")
		{
			int count = myMinHeap.availableDoctorCount();
			cout << "There are "<<count<<" doctors available\n";
			cout << '\n';
		}

		//Available Doctor Report (Level order print available)
		else if(choice == "8")
		{
			cout << "Doctors available at this time:\n";
			myMinHeap.levelOrderAvailable();
			cout << '\n';
		}

		//Busy Doctors List (Level order print not available)
		else if(choice == "9")
		{
			cout << "Doctors not available at this time:\n";
			myMinHeap.levelOrderBusy();
			cout << '\n';
		}

		//Exit
		else if(choice == "10")
		{
			return;
		}
	}
}

Executive::~Executive()
{

}
