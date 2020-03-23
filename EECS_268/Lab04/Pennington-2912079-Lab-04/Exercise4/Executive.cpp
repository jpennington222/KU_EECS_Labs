/*
 * @Author: Joseph Pennington
 * @File Name: Executive.cpp
 * @Assignment: EECS 268 Lab 04 Exercise 4
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
  int x = 0;
  strcpy(m_array, input.c_str());

  for(int i=0; i<size+1; i++)
  {
    if (m_array[i] == '(' || m_array[i] == ')' || m_array[i] == '{' || m_array[i] == '}' || m_array[i] == '[' || m_array[i] == ']')
    {
      new_size++;
    }
  }

  new_array = new char[new_size+1];
  for(int i=0; i<size+1; i++)
  {
    if(m_array[i] == '(' || m_array[i] == ')' || m_array[i] == '{' || m_array[i] == '}' || m_array[i] == '[' || m_array[i] == ']')
    {
      new_array[x] = m_array[i];
      x++;
    }
  }
}

void Executive::run()
{
  std::cout<<'\n';
  if(isBalanced(new_array, 0, new_size-1) == true)
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
  if(new_size % 2 != 0)
  {
    return(false);
  }

  else if (i < j)
  {
    if((array[i] == '(' && array[j] == ')') || (array[i] == '{' && array[j] == '}') || (array[i] == '[' || array[j] == ']') && i != j)
    {
      return(isBalanced(array, i+1, j-1));
    }
    else if((array[i] == ')' && array[j] == '(') || (array[i] == '}' && array[j] == '{') || (array[i] == ']' && array[j] == '[') && i !=j)
    {
      if((array[i-1] == '(' && array[j+1] == ')') || (array[i-1] == '{' && array[j-1] == '}') || (array[i-1] == '[' || array[j-1] == ']') && i != j )
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
  delete[] new_array;
}
