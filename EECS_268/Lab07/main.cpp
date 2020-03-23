/*
 * @Author: Joseph Pennington
 * @File Name: main.cpp
 * @Assignment: EECS 268 Lab 07
 * @Date: 10/30/2018
 * @Brief: This program is the main file for the lab. It saves the inputs and passes them to the class.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Executive.h"
using namespace std;

int main(int argc, char* argv[])
{
	srand48(0);
	if(argc == 4)
	{
		int size = atoi(argv[1]);
		string order = argv[2];
		string method = argv[3];
		if(order == "random" || order == "ascending" || order == "descending")
		{
			if(method == "selection" || method == "insertion" || method == "bubble" || method == "merge" || method == "quick")
			{
				Executive exec(size, order, method);
				exec.run();
			}

			else
			{
				cout<<"Incorrect Sorting Method\n";
			}
		}

		else
		{
			cout<<"Incorrect Order Specifier\n";
		}
	}

	else if(argc != 4)
	{
		cout<<'\n';
		cout<<"Incorrect Amount of Parameters\n";
		cout<<'\n';
	}

	return(0);
}
