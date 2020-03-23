/*
 * @Author: Joseph Pennington
 * @File Name: PrecondViolatedExcep.cpp
 * @Assignment: EECS 268 Lab 08
 * @Date: 11/13/2018
 * @Brief: This program is the cpp file for the PrecondViolatedExcep class
 */

 #include "PrecondViolatedExcep.h"
 #include <string>

 PrecondViolatedExcep::PrecondViolatedExcep(const std::string& message): logic_error("Precondition Violated Exception: " + message)
 {
 }
