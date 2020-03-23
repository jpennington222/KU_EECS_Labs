/*                                                                              
 * File Name: StudentRecord.h                                            
 * Author: Joseph Pennington                                                    
 * Assignment: EECS 268 Lab 01                                        
 * Description: This is the header file for the “StudentRecord” class. This file contains the variables and functions for the getters and setters.
 * Date: 09/02/2018                                                              
 */


#ifndef STUDENTRECORD_H
#define STUDENTRECORD_H
#include <string>

class StudentRecord
{
	public:
		std::string getdepcode(); 
		/*
		*pre: studentrecord must be made and not empty.
		*post: returns the department code.
		*return: returns a string with the deparment code.
		*/
		int getcoursenum(); 
		/*
		*pre: studentrecord must be made and not empty. 
		*post: returns the course number.
		*return: returns an int with the course number.
		*/
		int getstudentnum(); 
		/*
		*pre: studentrecord must be made and not empty. 
		*post: returns the total amount of students. 
		*return: returns int of total amount of students.
		*/
		int getstudentID(int index);
		/*
		*pre: studentrecord must be made and not empty.
		*post: returns a student ID at a given index.
		*return: returns an int of a studnet ID from an index of the array.
		*/
		void setdepcode(std::string DepCode); 
		/*
		*pre: studentrecord must be declared.
		*post: sets the department code.
		*return: none.
		*/
		void setcoursenum(int CourseNum );
		/*
		*pre: studentrecord must be declared.
		*post: sets the course code.
		*return: none.
		*/
		void setstudentnum(int StudentNum); 
		/*
		*pre: studentrecord must be declared.
		*post: sets the total amount of students.
		*return: none.
		*/
		void setstudentID(int* StudentID, int arr_size);
		/*
		*pre: studentrecord must be declared.
		*post: creates and fills a new array of student IDs
		*return: none.
		*/
		void remakestudentID();
		/*
		*pre: studentrecord must be declared.
		*post: deletes the contents of the student ID array.
		*return: none.
		*/
		~StudentRecord(); 
		/*
		*pre: studentrecord must be declared.
		*post: deletes the contents of the student ID array.
		*return: none.
		*/
	private:
		std::string depcode;
		int coursenum;
		int studentnum;
		int* studentID;
};
#endif


