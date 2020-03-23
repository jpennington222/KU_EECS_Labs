/*                                                                              
 * File Name: main.cpp                                            
 * Author: Joseph Pennington                                                    
 * Assignment: EECS 169 Lab 11 Exercise 1                                        
 * Description: This program will use classes to get, set, and alter values in an ArrayWrapper class
 * Date: 12/4/2017  
 * There are memory allocation errors                                                            
 */

#include "ArrayWrapper.h"
#include "ArrayWrapperDriver.h"
#include <iostream>
#include <fstream>
#include <string>

int main( int argc, char* argv[])
{
	std::string FileName;
	
	if(argc == 2)
	{
		FileName = argv[1];
		ArrayWrapperDriver myAWD(FileName);
		myAWD.run();
	}
	else if(argc != 2)
	{
		std::cout<<"Error opening file\n";
	}
	return(0);
}
