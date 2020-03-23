/*                                                                              
 * File Name: main.cpp                                            
 * Author: Joseph Pennington                                                    
 * Assignment: EECS 169 Lab 10 Exercise 1                                        
 * Description: This program will use classes to give information about drivers from a menu
 * Date: 11/21/2017                                                              
 */

#include "DMV.h"
#include "DriversLicenseRecord.h"
#include <iostream>
#include <fstream>
#include <string>

int main( int argc, char* argv[])
{
	std::string FileName;
	
	if(argc == 2)
	{
		FileName = argv[1];
		DMV myDMV(FileName);
		myDMV.run();
	}
	else if(argc != 2)
	{
		std::cout<<"Error opening file\n";
	}
	return(0);
}
