/*
 * @Author: Joseph Pennington
 * @File Name: BinaryNode.cpp
 * @Assignment: EECS 268 Lab 09
 * @Date: 12/04/2018
 * @Brief: This is the InvalidSetEntryRequestcpp header file
 */

 #ifndef _INVALID_SET_ENTRY_REQUEST
 #define _INVALID_SET_ENTRY_REQUEST

 #include <stdexcept>
 #include <string>

 using namespace std;

 class InvalidSetEntryRequest : public logic_error
 {
 public:

   /*
   * @pre: Error must be encountered
   * @post: Error is thrown
   * @param message: Message that contains the description of the error
   * @return: none
   */

    InvalidSetEntryRequest(const string& message = "");
 };
 #endif
