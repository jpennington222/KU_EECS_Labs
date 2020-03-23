/*
 * @Author: Joseph Pennington
 * @File Name: BinaryNode.cpp
 * @Assignment: EECS 268 Lab 09
 * @Date: 12/04/2018
 * @Brief: This is the NotFoundException header file
 */

 #ifndef _NOT_FOUND_EXCEPTION
 #define _NOT_FOUND_EXCEPTION

 #include <stdexcept>
 #include <string>

 using namespace std;

 class NotFoundException : public logic_error
 {
 public:

   /*
   * @pre: Error must be encountered
   * @post: Error is thrown
   * @param message: Message that contains the description of the error
   * @return: none
   */

    NotFoundException(const string& message = "");
 };
 #endif
