/*
 * @Author: Joseph Pennington
 * @File Name: Task.cpp
 * @Assignment: EECS 268 Lab 09
 * @Date: 12/04/2018
 * @Brief: This program is the cpp for the Task class
 */


#include"Task.h"
Task::Task()
{

}
Task::Task(int TID, string TN, int ETTC, int TATB, int TS)
{
  taskID = TID;
  taskName = TN;
  estimatedTimeToComplete = ETTC;
  timeAddedToBST = TATB;
  timeStarted = TS;
}

int Task::gettaskID()
{
  return(taskID);
}

string Task::gettaskName()
{
  return(taskName);
}

int Task::getestimatedTimeToComplete()
{
  return(estimatedTimeToComplete);
}

int Task::gettimeAddedToBST()
{
  return(timeAddedToBST);
}

int Task::gettimeStarted()
{
  return(timeStarted);
}

bool Task::operator>(const Task& rightHandSide)
{
  return(taskID>rightHandSide.taskID);
}

bool Task::operator<(const Task& rightHandSide)
{
  return(taskID<rightHandSide.taskID);
}

bool Task::operator==(const Task& rightHandSide)
{
  bool same=(taskID==rightHandSide.taskID);
  return(same);
}

bool Task::operator==(const int& rightHandSide)
{
  return(rightHandSide==taskID);
}

bool Task::operator>(const int& rightHandSide)
{
  return(taskID>rightHandSide);
}

bool Task::operator<(const int& rightHandSide)
{
  return(taskID<rightHandSide);
}
