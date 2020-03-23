/*                                                                              
 * File Name: StudentRecordDriver.h                                            
 * Author: Joseph Pennington                                                    
 * Assignment: EECS 268 Lab 01                                        
 * Description: This program is the header file for the “StudentRecordDriver” class. This class contains the functions to run the menu and read in the file.
 * Date: 09/02/2018                                                              
 */


#ifndef STUDENTRECORDDRIVER_H
#define STUDENTRECORDDRIVER_H
#include "StudentRecord.h"
#include <string>
#include <iostream>

class StudentRecordDriver
{
	public:
		StudentRecordDriver(std::string FileName);
		/*
		*pre: filename must be given when running the program.
		*post: 2 StudentRecords are made from the contents of the in file.
		*return: none.
		*/
		void run();
		/*
		*pre: studentrecords are made. 
		*post: post: runs the prorgam and contains the menu the user interacts with.
		*return: none.
		*/
	private:
		StudentRecord* record;
		StudentRecord* recordcopy;
		int recordsize;
};
#endif
    

