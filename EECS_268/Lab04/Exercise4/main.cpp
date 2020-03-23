/*
 * @Author: Joseph Pennington
 * @File Name: main.cpp
 * @Assignment: EECS 268 Lab 04 Exercise 4
 * @Date: 10/01/2018
 * @Brief: This program is the main file for the lab. It saves the input and passes of the work to the classes.
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
		std::cout<<"Error opening program\n";
	}

	return(0);
}
