/*                                                                              
 * File Name: main.cpp                                            
 * Author: Joseph Pennington                                                    
 * Assignment: EECS 268 Lab 01                                        
 * Description: This program will use classes to give information about class rosters including course code, ID, total number of students, and student IDs
 * Date: 09/02/2018                                                              
 */

#include "StudentRecord.h"
#include "StudentRecordDriver.h"
#include <iostream>
#include <fstream>
#include <string>

int main( int argc, char* argv[])
{
	std::string FileName;
    
	if(argc == 2)
	{
		FileName = argv[1];
		StudentRecordDriver myStudentRecordDriver(FileName);
		myStudentRecordDriver.run();
	}
	else if(argc != 2) 
	{
		std::cout<<"Error opening file\n";
	}
	return(0);
}

