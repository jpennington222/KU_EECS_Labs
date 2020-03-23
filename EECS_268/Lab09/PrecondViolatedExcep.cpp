/*
 * @Author: Joseph Pennington
 * @File Name: PrecondViolatedExcep.cpp
 * @Assignment: EECS 268 Lab 09
 * @Date: 12/04/2018
 * @Brief: This program is the cpp file for the PrecondViolatedExcep class
 */

 #include "PrecondViolatedExcep.h"
 #include <string>

 PrecondViolatedExcep::PrecondViolatedExcep(const std::string& message): logic_error("Precondition Violated Exception: " + message)
 {
 }
