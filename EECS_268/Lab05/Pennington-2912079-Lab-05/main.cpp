/*
 * @Author: Joseph Pennington
 * @File Name: main.cpp
 * @Assignment: EECS 268 Lab 05
 * @Date: 10/08/2018
 * @Brief: This program is the main file for the lab. It saves the input file name and passes of the work to the classes.
 */

#include <iostream>
#include <string>
#include <fstream>
#include "Executive.h"


bool Exists(std::string file);

int main(int argc, char* argv[])
{
	if(argc == 2)
	{
    bool exist = true;
    exist = Exists(argv[1]);
    if (exist == true)
    {
		    Executive exec(argv[1]);
        if((exec.getRow()-1 > 1 && exec.getCol()-1 > 1) && (exec.getStartR() <= exec.getRow()-1 && exec.getStartC() <= exec.getCol()-1))
        {
		        exec.run();
        }

	else
	{
		std::cout<<"Invalid starting position\n";
	}
    }

    else
    {
      std::cout<<"Incorrect File Name\n";
    }
	}
	else if(argc != 2)
	{
		std::cout<<"Incorrect Number of Parameters\n";
	}

	return(0);
}

bool Exists(std::string file)
{
  std::ifstream f(file.c_str());
  return(f.good());
}
