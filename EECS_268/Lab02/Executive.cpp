/*
 * @Author: Joseph Pennington
 * @File Name: Executive.cpp
 * @Assignment: EECS 268 Lab 02
 * @Date: 09/17/2018
 * @Brief: This program is the Executive.cpp file for the lab. It passes the inFile contents to the respective functions.
 */

#include "Executive.h"
#include "WebBrowserInterface.h"
#include "ListInterface.h"
#include "Node.h"
#include "LinkedList.h"
#include "WebBrowser.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

Executive::Executive(std::string Filename)
{
	file = Filename;
	history = new WebBrowser();
}

void Executive::run()
{
	std::string Command = "";
	std::string url = "";
	std::ifstream inFile;
	inFile.open(file);

	if(inFile.is_open() == false)
	{
		std::cout<<"Error Opening File"<<"\n";
		exit(0);
	}

	while(!inFile.eof())
	{
		Command == "";
		inFile>>Command;
		if(Command=="") break;

		if(Command == "NAVIGATE")
		{
			inFile>>url;
			history -> navigateTo(url);
		}

		if(Command == "HISTORY")
		{
			LinkedList<std::string>* temp = new LinkedList<std::string>();
			history -> copyCurrentHistory(*temp);
			std::cout<<'\n'<<"Oldest"<<'\n';
			std::cout<<"===========\n";
			for(int i=1; i <= (temp -> getLength()); i++)
			{
				try
				{
					std::cout<<temp -> getEntry(i);
					if(temp -> getEntry(i) == history -> currentURL())
					{
						std::cout<<" <==current";
					}
					std::cout<<'\n';
				}

				catch(std::runtime_error error)
				{
					std::cout<<error.what()<<'\n';
				}
			}

			std::cout<<"===========\n";
			std::cout<<"Newest\n";
			delete temp;
			Command = "";
		}

		if(Command == "BACK")
		{
			history -> back();
		}

		if(Command == "FORWARD")
		{
			history -> forward();
		}
	}

	inFile.close();
}

Executive::~Executive()
{
	delete history;
}
