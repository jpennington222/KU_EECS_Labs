/*
 * @Author: Joseph Pennington
 * @File Name: main.cpp
 * @Assignment: EECS 268 Lab 09
 * @Date: 12/13/2018
 * @Brief: This is the main.cpp file. It saves the input file name and passes of the work to the classes.
 */

#include <iostream>
#include <string>
#include <fstream>
#include "Executive.h"
using namespace std;


bool Exists(string file);

int main(int argc, char* argv[])
{
	cout<<'\n';
	if(argc == 2)
	{

    bool exist = true;
		string file = argv[1];
    exist = Exists(file);

    if (exist == true)
    {
		    Executive exec(file);
				exec.run();
		}

    else
    {
      std::cout<<"Incorrect File Name or Parameter\n";
    }
	}

	else if(argc != 2)
	{
		std::cout<<"Incorrect Number of Parameters\n";
	}

	cout<<'\n';
	return(0);
}

bool Exists(string file)
{
  ifstream f(file.c_str());
  return(f.good());
}
