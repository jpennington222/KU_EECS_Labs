/*
 * @Author: Joseph Pennington
 * @File Name: Task.h
 * @Assignment: EECS 268 Lab 09
 * @Date: 12/04/2018
 * @Brief: This program is the header file for the Task class
 */


#ifndef TASK_H
#define TASK_H
#include<string>

using namespace std;

class Task
{
public:

  /*
   * @pre: none
   * @post: none
   * @return: none
   */

  Task();

  /*
   * @pre: none
   * @post: saves private variables
   * @param TID: taskID
   * @param TN: taskName
   * @param ETTC: estimatedTimeToComplete
   * @param TATB: timeAddedToBST
   * @param TS: timeStarted
   * @return: none
   */

  Task(int TID, string TN, int ETTC, int TATB, int TS);

  /*
   * @pre: task created
   * @post: returns taskID
   * @return: taskID
   */

  int gettaskID();

  /*
   * @pre: task created
   * @post: returns taskName
   * @return: taskName
   */

  string gettaskName();

  /*
   * @pre: task created
   * @post: returns ETTC
   * @return: ETTC
   */

  int getestimatedTimeToComplete();

  /*
   * @pre: task created
   * @post: returns timeAddedToBST
   * @return: timeAddedToBST
   */

  int gettimeAddedToBST();

  /*
   * @pre: task created
   * @post: returns timeStarted
   * @return: timestarted
   */

  int gettimeStarted();

  /*
   * @pre: task created
   * @post: returns whether the taskID is greater
   * @return: true is taskID is greater than RHS
   */

  bool operator>(const Task& rightHandSide);

  /*
   * @pre: task created
   * @post: returns whether the taskID is less
   * @return: true is taskID is less than RHS
   */

  bool operator<(const Task& rightHandSide);

  /*
   * @pre: task created
   * @post: returns whether the taskID is equal
   * @return: true is taskID is equal than RHS
   */

  bool operator==(const Task& rightHandSide);

  /*
   * @pre: task created
   * @post: returns whether the taskID is equal
   * @return: true is taskID is equal than RHS
   */

  bool operator==(const int& rightHandSide);

  /*
   * @pre: task created
   * @post: returns whether the taskID is greater
   * @return: true is taskID is greater than RHS
   */

  bool operator>(const int& rightHandSide);

  /*
   * @pre: task created
   * @post: returns whether the taskID is less
   * @return: true is taskID is less than RHS
   */

  bool operator<(const int& rightHandSide);


private:
  int taskID;
  string taskName;
  int estimatedTimeToComplete;
  int timeAddedToBST;
  int timeStarted;
};
#endif
