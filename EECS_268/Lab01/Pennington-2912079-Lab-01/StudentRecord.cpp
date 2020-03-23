/*                                                                              
 * File Name: StudentRecord.cpp                                            
 * Author: Joseph Pennington                                                    
 * Assignment: EECS 268 Lab 01                                        
 * Description: This program is the cpp file for the “StudentRecord” class. This class contains the getters and setters for the class.
 * Date: 09/02/2018                                                              
 */


#include <iostream>
#include <string>
#include "StudentRecord.h"

std::string StudentRecord::getdepcode()//returns department code
{
	return depcode;
}

int StudentRecord::getcoursenum()//returns course number
{
	return coursenum;
}

int StudentRecord::getstudentnum()//returns total amount of students in a class
{
	return studentnum;
}

int StudentRecord::getstudentID(int index)//returns a student ID
{
	return studentID[index];
}

void StudentRecord::setdepcode(std::string DepCode)//sets department code
{
	depcode = DepCode;
}

void StudentRecord::setcoursenum(int CourseNum)//sets course number
{
	coursenum = CourseNum;
}

void StudentRecord::setstudentnum(int StudentNum)//sets total number of students in a class
{
	studentnum = StudentNum;
}

void StudentRecord::setstudentID(int* StudentID, int arr_size)//sets the array of student IDs
{
	studentID = new int[arr_size];
	for(int i=0; i<arr_size; i++)
	{
		studentID[i] = StudentID[i];
	}
}

void StudentRecord::remakestudentID()//deltes the student ID array for swapping
{
	delete[] studentID;
}

StudentRecord::~StudentRecord()//deletes remaining student ID arrays
{
	delete[] studentID;
}




