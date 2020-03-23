/*
 * @Author: Joseph Pennington
 * @File Name: main.cpp
 * @Assignment: EECS 268 Lab 04 Exercise 3
 * @Date: 10/01/2018
 * @Brief: This program is the main file for the lab. It saves the inputs and passes them to the class.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Executive.h"

int main(int argc, char* argv[])
{
	if(argc == 3)
	{
		int num = atoi(argv[2]);
		Executive exec(argv[1], num);
		exec.run();
	}
	else if(argc != 3)
	{
		std::cout<<'\n';
		std::cout<<"Incorrect Amount of Parameters\n";
		std::cout<<'\n';
	}

	return(0);
}
