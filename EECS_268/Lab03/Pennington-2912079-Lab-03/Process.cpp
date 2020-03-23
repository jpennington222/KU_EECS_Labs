/*
 * @Author: Joseph Pennington
 * @File Name: Process.cpp
 * @Assignment: EECS 268 Lab 03
 * @Date: 09/24/2018
 * @Brief: This program is the Process.cpp file for the lab. It has the constructor, Call, Return, checkRetrun, copyProcess, operator=, and destructor function
 */

#include "Process.h"
#include <iostream>
#include <string>

Process::Process(std::string process)
{
  name = process;
  stringstack = new Stack<std::string*>();
  std::cout<<name <<" has been added to queue\n";
  std::string* stringptr1 = new std::string("main"); //memory
  stringstack -> push(stringptr1);
}

void Process::Call(std::string function)
{
  try
  {
    std::string* stringptr2 = new std::string(function); //memory
    stringstack -> push(stringptr2);
    std::cout<<name<<" calls "<<function<<'\n';
  }

  catch(PrecondViolatedExcep error)
  {
    std::cout<<"Call Error\n";
  }
}

void Process::Return()
{
  if(stringstack -> isEmpty())
  {
    std::cout<<name<<" process has ended\n";
  }

  else
  {
    std::string* temp = stringstack -> peek();
    try
    {
      stringstack -> pop();
      std::cout<<name<<" returns from "<<*temp<<'\n';

      if(stringstack -> isEmpty())
      {
        std::cout<<name<<" process has ended\n";
      }
    }

    catch(PrecondViolatedExcep error)
    {
      std::cout<<"Return Error\n";
    }
  }
}

bool Process::checkReturn()
{
  if(stringstack -> isEmpty() ==true)
  {
    return(true);
  }
  else
  {
    return(false);
  }
}

Process::Process(const Process& original)
{
  stringstack = new Stack<std::string*>();
  *this = original;
}

void Process::operator=(const Process& rhs)
{
  name = rhs.name;
  stringstack = rhs.stringstack;
}

Process::~Process()
{
  delete stringstack;
  delete stringptr1;
  delete stringptr2;
}
