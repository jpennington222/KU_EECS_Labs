/*
 * @Author: Joseph Pennington
 * @File Name: Executive.cpp
 * @Assignment: EECS 268 Lab 04 Exercise 1
 * @Date: 10/01/2018
 * @Brief: This program is the Executive.cpp file for the lab. It creates an array of the parenthesis and passes it to the isBalanced function
 */

#include "Executive.h"
#include <iostream>
#include <string>
#include <cstring>

Executive::Executive(std::string Input)
{
  input = Input;
  size = input.length();
  m_array = new char[size+1];
  strcpy(m_array, input.c_str());
}

void Executive::run()
{
  std::cout<<'\n';
  if(isBalanced(m_array, 0, size-1) == true)
  {
    std::cout<<"The sequence "<<input<<" is balanced\n\n";
  }

  else
  {
    std::cout<<"The sequence "<<input<<" is not balanced\n\n";
  }
}

bool Executive::isBalanced(char* array, int i, int j)
{
  if(size % 2 != 0)
  {
    return(false);
  }

  else if (i < j)
  {
    if(array[i] == '(' && array[j] == ')' && i != j)
    {
      return(isBalanced(array, i+1, j-1));
    }
    else if(array[i] == ')' && array[j] == '(' && i !=j)
    {
      if(array[i-1] == '(' && array[j+1] == ')')
      {
        return(isBalanced(array, i+1, j-1));
      }
      else
      {
        return(false);
      }
    }
    else
    {
      return(false);
    }
  }
}

Executive::~Executive()
{
  delete[] m_array;
}
