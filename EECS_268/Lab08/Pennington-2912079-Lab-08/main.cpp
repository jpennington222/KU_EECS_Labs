/*
 * @Author: Joseph Pennington
 * @File Name: main.cpp
 * @Assignment: EECS 268 Lab 08
 * @Date: 11/13/2018
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
	if(argc == 3)
	{

    bool exist = true;
		string file = argv[2];
    exist = Exists(file);
		string order = argv[1];

    if (exist == true)
    {
			if(order == "postfix" || order == "prefix")
			{
				//cout<<"hi"<<'\n';
		    Executive exec(order, file);
		    exec.run();
			}

			else
			{
				cout<<"Enter postfix or prefix\n";
			}
		}

    else
    {
      std::cout<<"Incorrect File Name or Parameter\n";
    }
	}
	else if(argc != 3)
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
