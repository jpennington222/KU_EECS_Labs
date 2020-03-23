/*
 * @Author: Joseph Pennington
 * @File Name: main.cpp
 * @Assignment: EECS 268 Lab 06
 * @Date: 10/16/2018
 * @Brief: This program is the main file for the lab. It saves the input file name and passes of the work to the classes.
 */

#include <iostream>
#include <string>
#include <fstream>
#include "Executive.h"

int main()
{
  Executive exec("Question.txt", "Answer.txt");
  exec.run();
  return(0);
}
