/*
 * @Author: Joseph Pennington
 * @File Name: Executive.h
 * @Assignment: EECS 560 Lab 08
 * @Brief: This program is the header file for the Exeuctive Class.
 */

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include <fstream>
#include <iostream>
#include "maxMinHeap.h"
#include "BSTEntry.h"

class Executive
{
	public:

		/*
		* @pre: none
		* @post: The file name is stored into the private member variable
		* @param Filename: A string represting the file name
		* @return: none
		*/

		Executive(std::string Filename);

		/*
		* @pre: The file name must have been saved
		* @post: Handles all function calls depending on file contents
		* @return: none
		*/

		void run();

		/*
		* @pre: Object made
		* @post: Deletes the object
		* @return: none
		*/

		~Executive();

	private:

		//Filename
		std::string file;

		//MaxMin Heap
		maxMinHeap<BSTEntry> myHeap;


};
#endif
