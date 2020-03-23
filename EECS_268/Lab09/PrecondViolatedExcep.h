/*
 * @Author: Joseph Pennington
 * @File Name: PrecondViolatedExcep.h
 * @Assignment: EECS 268 Lab 09
 * @Date: 12/04/2018
 * @Brief: This program is the header file for the PrecondViolatedExcep class
 */

#ifndef _PRECOND_VIOLATED_EXCEP
#define _PRECOND_VIOLATED_EXCEP

#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolatedExcep : public logic_error
{
public:

  /*
  * @pre: Error must be encountered
  * @post: Error is thrown
  * @param message: Message that contains the description of the error
  * @return: none
  */

   PrecondViolatedExcep(const string& message = "");
}; // end PrecondViolatedExcep
#endif
