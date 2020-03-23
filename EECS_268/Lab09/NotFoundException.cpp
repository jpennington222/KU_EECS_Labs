/*
 * @Author: Joseph Pennington
 * @File Name: BinaryNode.cpp
 * @Assignment: EECS 268 Lab 09
 * @Date: 12/04/2018
 * @Brief: This is the NotFoundException cpp file
 */

 #include "NotFoundException.h"
 #include <string>

 NotFoundException::NotFoundException(const std::string& message): logic_error("Not Found Exception: " + message)
 {
 }
