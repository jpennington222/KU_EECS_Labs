/*
 * @Author: Joseph Pennington
 * @File Name: Executive.cpp
 * @Assignment: EECS 268 Lab 04 Exercise 3
 * @Date: 10/01/2018
 * @Brief: This program is the Executive.cpp file for the lab. It saves the flag and number
 */

#include "Executive.h"
#include <iostream>
#include <string>
#include <cstring>

Executive::Executive(std::string choice, int num)
{
  Choice = choice;
  Num = num;
}

void Executive::run()
{
  int i = 0;
  bool v = false;

  std::cout<<'\n';

  if(Choice == "-i")
  {
    i = I(Num);
    std::cout<<i<<"\n\n";
  }

  else if (Choice == "-v")
  {
    v = V(0, 1, Num);
    if(v == true)
    {
      std::cout<<Num<<" is in the sequence\n\n";
    }

    else if(v == false)
    {
      std::cout<<Num<<" is not in the sequence\n\n";
    }
  }

  else
  {
    std::cout<<"Insert Flag -i or -v\n\n";
  }
}

int Executive::I(int num)
{
  if(num == 0 || num == 1)
  {
    return(num);
  }

  else
  {
    return(I(num-1) + I(num-2));
  }
}

bool Executive::V(int first, int second, int checkNum)
{
  if(checkNum == 0)
  {
    return(true);
  }

  else
  {
	int store = 0;
	store = first + second;
	if (store == checkNum)
	{
		return(true);
	}

	else if(store != checkNum && checkNum > store)
	{
		return(V(second, store, checkNum));
	}

	else
	{
		return(false);
	}
  }
}
