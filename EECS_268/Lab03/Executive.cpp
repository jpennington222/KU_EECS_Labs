/*
 * @Author: Joseph Pennington
 * @File Name: Executive.cpp
 * @Assignment: EECS 268 Lab 03
 * @Date: 09/24/2018
 * @Brief: This program is the Executive.cpp file for the lab. It passes the inFile contents to the respective functions.
 */

#include "Executive.h"
#include "QueueInterface.h"
#include "StackInterface.h"
#include "Node.h"
#include "Stack.h"
#include "Queue.h"
#include "PrecondViolatedExcep.h"
#include <iostream>
#include <fstream>
#include <string>

Executive::Executive(std::string Filename)
{
  file = Filename;
  ProcessQ = new Queue<Process*>();
}

void Executive::run()
{
  std::string command = "";
  std::string process = "";
  std::string function = "";
  std::ifstream inFile;
  inFile.open(file);

  if(inFile.is_open() == false)
  {
    std::cout<<"Error Opening File"<<"\n";
    exit(0);
  }

  while(!inFile.eof())
  {
    command = "";
    process = "";
    function = "";
    inFile>>command;
    if(command == "") break;

    if(command == "START")
    {
      inFile>>process;
      Process* tempProcess = new Process(process); //memory
      ProcessQ -> enqueue(tempProcess);
    }

    if(command == "CALL")
    {
      inFile>>function;
      Process* temp = ProcessQ -> peekFront();
      ProcessQ -> peekFront() -> Call(function);
      ProcessQ -> dequeue();
      ProcessQ -> enqueue(temp);
    }

    if (command == "RETURN")
    {
      ProcessQ -> peekFront() -> Return();
      if(ProcessQ -> peekFront() -> checkReturn() == true)
      {
        ProcessQ -> dequeue();
      }

    }
  }
}

Executive::~Executive()
{
  delete ProcessQ;
  delete tempProcess;
  //delete exec;
}
