/*
 * @Author: Joseph Pennington
 * @File Name: Executive.cpp
 * @Assignment: EECS 268 Lab 04 Exercise 2
 * @Date: 10/01/2018
 * @Brief: This program is the Executive.cpp file for the lab. It passes the string into the permute function
 */

#include "Executive.h"
#include <iostream>
#include <string>
#include <cstring>

Executive::Executive(std::string Input)
{
  input = Input;
  size = input.length();
}

void Executive::run()
{
  std::string Front = "";
  std::cout<<'\n';
  permute(Front, input);
  std::cout<<'\n';
}

void Executive::permute(std::string Front, std::string Back)
{
  for(int i = 0; i<Back.length(); i++)
  {
    std::string newFront = Front + Back[i];
    std::cout<<newFront<<'\n';
    std::string newBack = Back.substr(0,i) + Back.substr(i+1);
    permute(newFront, newBack);
  }
}
