/*
 * @Author: Joseph Pennington
 * @File Name: main.cpp
 * @Assignment: EECS 268 Lab 03
 * @Date: 09/24/2018
 * @Brief: This program is the main file for the lab. It saves the input file name and passes of the work to the classes.
 */

#include <iostream>
#include <string>
#include <fstream>
#include "Executive.h"

int main(int argc, char* argv[])
{
	if(argc == 2)
	{
		Executive exec(argv[1]);
		exec.run();
	}
	else if(argc != 2)
	{
		std::cout<<"Error opening file\n";
	}

	return(0);
}
