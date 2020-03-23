/*
 * @Author: Joseph Pennington
 * @File Name: BinaryNode.cpp
 * @Assignment: EECS 268 Lab 09
 * @Date: 12/04/2018
 * @Brief: This is the InvalidSetEntryRequestcpp file
 */

 #include "InvalidSetEntryRequest.h"
 #include <string>

 InvalidSetEntryRequestp::InvalidSetEntryRequestp(const std::string& message): logic_error("Invalid Set Entry Request: " + message)
 {
 }
