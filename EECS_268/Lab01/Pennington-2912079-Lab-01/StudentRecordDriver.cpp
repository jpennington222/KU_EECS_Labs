/*                                                                              
 * File Name: StudentRecordDriver.cpp                                            
 * Author: Joseph Pennington                                                    
 * Assignment: EECS 268 Lab 01                                        
 * Description: This file is the cpp file for the “StudentRecordDriver” Class. It will use classes to give information about class rosters including course code, ID, total number of students, and student IDs by using menu. This uses both the “StudentRecord” and “StudentRecordDriver” classes.
 * Date: 09/02/2018                                                              
 */


#include "StudentRecord.h"
#include "StudentRecordDriver.h"
#include <iostream>
#include <fstream>
#include <string>

StudentRecordDriver::StudentRecordDriver(std::string FileName)//reads in file and stores info into 2 StudentRecords
{
	std::string DC;
	int CN;
	int SN;
	int SID;    
	int size = 0;
	int* ID_arr = nullptr;

	std::ifstream inFile;
	inFile.open (FileName);
	inFile>>size;
	recordsize = size;
	record = new StudentRecord[recordsize];
	recordcopy = new StudentRecord[recordsize];

	for(int i=0; i<size; i++)
        {
		inFile>>DC;
		record[i].setdepcode(DC);
		recordcopy[i].setdepcode(DC);
		inFile>>CN;
		record[i].setcoursenum(CN);
		recordcopy[i].setcoursenum(CN);
		inFile>>SN;
		record[i].setstudentnum(SN);
		recordcopy[i].setstudentnum(SN);
		ID_arr = new int[SN];
		for(int j=0; j<SN; j++)
		{
			inFile>>SID;
			ID_arr[j] = SID;
		}
		record[i].setstudentID(ID_arr, SN);
		recordcopy[i].setstudentID(ID_arr, SN);
		delete[] ID_arr;
	}
	inFile.close();
}

void StudentRecordDriver::run()//makes the menu the user interacts with
{
	int choice = 0;
	std::string Dep_Code;
	int count = 0;
	int Course_Num = 0;
	int largest_num = 0;
	int temp_size = 0;
	int temp_ID = 0;
	std::string temp_depcode;
	int temp_studentnum = 0;
	int temp_swap = 0;
	int temp_IDS = 0;
	int* temp_ID_arr = nullptr;
	int* temp_ID_arr2 = nullptr;
	std::string temp_swap_string;
	std::string class1;
	std::string class2;
	int class1num = 0;
	int class2num = 0;
	int swap1 = 0;
	int swap2 = 0;
	int temp_swap1 = 0;
	int temp_swap2 = 0;
	int check1 = 0;
	int check2 = 0;
	int check3 = 0;
    
	while (choice != 7)
	{
		count = 0;
		check1 = 0;
		check2 = 0;
		check3 = 0;
		std::cout<<"Select an option: \n";
		std::cout<<"1) Print All Courses\n";
		std::cout<<"2) Print All Courses for a Department \n";
		std::cout<<"3) Print Roster for a Course\n";
		std::cout<<"4) Print Largest Class\n";
		std::cout<<"5) Swap Two Classes\n";
		std::cout<<"6) Print Schedule for a Student\n";
		std::cout<<"7) Exit\n";
		std::cout<<"Enter your choice: ";
		std::cin>>choice;

		std::cout<<'\n';
        
		if(choice == 1)//Print all courses
		{
			for(int i=0; i<recordsize; i++)
			{
				std::cout<<record[i].getdepcode()<<" "<<record[i].getcoursenum()<<'\n';
			}
		std::cout<<'\n';
		}

		else if(choice == 2)//Print all courses for a department
		{
			std::cout<<"Input Department Code: ";
			std::cin>>Dep_Code;
			for(int i=0; i<recordsize; i++)
			{
				if(record[i].getdepcode() == Dep_Code)
				{
					std::cout<<record[i].getdepcode()<<" "<<record[i].getcoursenum()<<'\n';
					count++;
				}
			}
			if(count == 0)
			{
				std::cout<<"Department Not Found\n";
			}
			std::cout<<'\n';
		}
    
		else if(choice == 3)//print roster for a course
		{
			std::cout<<"Input Department Code: ";
			std::cin>>Dep_Code;
			std::cout<<"Input Course Number: ";
			std::cin>>Course_Num;

			for(int i=0; i<recordsize; i++)
			{
				if(record[i].getdepcode() == Dep_Code && record[i].getcoursenum() == Course_Num)
				{
					temp_studentnum = record[i].getstudentnum();
					count++;
					for(int j=0; j<temp_studentnum; j++)
					{
						std::cout<<record[i].getstudentID(j);
						if(j<(temp_studentnum-1))
						{
							std::cout<<", ";
						}
					}
				}
			}
			if(count == 0)
			{
				std::cout<<"Class Not Found\n";
			}

			std::cout<<'\n'<<'\n';
		}
    
		else if(choice == 4)//print largest class
		{
			for(int i=0; i<recordsize; i++)
			{
				if(record[i].getstudentnum() > largest_num)
				{
					largest_num = record[i].getstudentnum();
				}
			}
			for(int i=0; i<recordsize; i++)
			{
				if(record[i].getstudentnum() == largest_num)
				{
					std::cout<<record[i].getdepcode()<<" "<<record[i].getcoursenum()<<" "<<record[i].getstudentnum()<<'\n'<<'\n';
				}
			}
		}
    
		else if(choice == 5)//swap 2 classes
		{
			std::cout<<"Input First Class Department Code: ";
			std::cin>>class1;
			std::cout<<"Input First Class Course Number: ";
			std::cin>>class1num;
			std::cout<<"Input Second Class Department Code: ";
			std::cin>>class2;
			std::cout<<"Input Second Class Course Number: ";
			std::cin>>class2num;

			for(int i=0; i<recordsize; i++)
			{
				if(class1 == record[i].getdepcode() && class1num == record[i].getcoursenum())
				{
					swap1 = i;
					check1++;
				}
				if(class2 == record[i].getdepcode() && class2num == record[i].getcoursenum())
				{
					swap2 = i;
					check2++;
				}

			}
			
			for(int i=0; i<recordsize; i++)
			{
				if(check1 != 0 && check2 != 0)
				{
					if((class1 != record[i].getdepcode() && class1num != record[i].getcoursenum())	&& (class2 != record[i].getdepcode() && class2num != record[i].getcoursenum()))
					{
						//set department code
						temp_swap_string = record[i].getdepcode();
						record[i].setdepcode(temp_swap_string);
				
						//set course number
						temp_swap = record[i].getcoursenum();
						record[i].setcoursenum(temp_swap);

						//set student number
						temp_swap = record[i].getstudentnum();
						record[i].setstudentnum(temp_swap);

						temp_ID_arr = new int[temp_swap];
						//set IDs
						for(int j=0; j<temp_swap; j++)
						{
							temp_IDS = record[i].getstudentID(j);
							temp_ID_arr[j] = temp_IDS;
						}
						record[i].setstudentID(temp_ID_arr, temp_swap);
						delete[] temp_ID_arr;
					}
					else
					{
						//swap department code
						temp_swap_string = recordcopy[swap1].getdepcode();
						record[swap2].setdepcode(temp_swap_string);
						temp_swap_string = recordcopy[swap2].getdepcode();
						record[swap1].setdepcode(temp_swap_string);

						//swap course number
						temp_swap = recordcopy[swap1].getcoursenum();
						record[swap2].setcoursenum(temp_swap);
						temp_swap = recordcopy[swap2].getcoursenum();
						record[swap1].setcoursenum(temp_swap);
	
						//swap student number
						temp_swap1 = recordcopy[swap1].getstudentnum();
						record[swap2].setstudentnum(temp_swap1);
						temp_swap2 = recordcopy[swap2].getstudentnum();
						record[swap1].setstudentnum(temp_swap2);
		
						temp_ID_arr = new int[temp_swap1];
						temp_swap = record[swap2].getstudentnum();
						temp_ID_arr2 = new int[temp_swap2];
	
						//swap IDS
						for(int j=0; j<temp_swap1; j++)
						{
							temp_IDS = recordcopy[swap1].getstudentID(j);
							temp_ID_arr[j] = temp_IDS;
						}
						for(int j=0; j<temp_swap2; j++)
						{
							temp_IDS = recordcopy[swap2].getstudentID(j);
							temp_ID_arr2[j] = temp_IDS;
						}
						record[swap1].remakestudentID();
						record[swap2].remakestudentID();

						record[swap2].setstudentID(temp_ID_arr, temp_swap1);
						record[swap1].setstudentID(temp_ID_arr2, temp_swap2);
		
						delete[] temp_ID_arr;
						delete[] temp_ID_arr2;
					}
				}

				else if(check3 == 0)
				{
					std::cout<<"Class Not Found"<<'\n';
					check3++;
				}
			}
		std::cout<<'\n';				
		}

		else if(choice == 6)//print student schedule
		{
			std::cout<<"Input Student ID Number: ";
			std::cin>>temp_ID;
			for(int i=0; i<recordsize; i++)
			{
				temp_size = record[i].getstudentnum();
				for(int j=0; j<temp_size; j++)
				{
					if(temp_ID == record[i].getstudentID(j))
					{
						std::cout<<record[i].getdepcode()<<" "<<record[i].getcoursenum()<<'\n';
						count++;
					}
				}
			}
			if(count == 0)
			{
				std::cout<<"Student Not Found\n";
			}
			std::cout<<'\n';
		}

		else if(choice != 7)//check for valid input
		{
			std::cout<<"Please Input a Number Between 1 and 7\n\n";
		}
	}
	std::cout<<"Goodbye\n\n";
	delete[] record;
	delete[] recordcopy;
}	

            
            
            




