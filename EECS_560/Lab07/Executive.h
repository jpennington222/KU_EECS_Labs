/*
 * @Author: Joseph Pennington
 * @File Name: Executive.h
 * @Assignment: EECS 560 Lab 07
 * @Brief: This program is the header file for the Exeuctive Class.
 */

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include <fstream>
#include <iostream>
#include "minHeap.h"
#include "maxHeap.h"
#include "BSTEntry.h"

class Executive
{
	public:

		/*
		* @pre: none
		* @post: The file name is stored into the private member variable
		* @param url: A string represting the file name
		* @return: none
		*/

		Executive(std::string Filename, std::string Filename2);

		/*
		* @pre: The file name must have been saved
		* @post: Handles all function calls depending on file contents
		* @return: none
		*/

		void run();

		/*
		* @pre: The file name must have been saved
		* @post: Handles all function calls for the min heap (doctors)
		* @return: none
		*/

		void minMenu();

		/*
		* @pre: The file name must have been saved
		* @post: Handles all function calls for the max heap (patients)
		* @return: none
		*/

    void maxMenu();

		/*
		* @pre: Heaps made
		* @post: Deletes the heap object
		* @return: none
		*/

		~Executive();

	private:

		//Filenames
		std::string file1;
		std::string file2;

		//Heaps
		minHeap<BSTEntry> myMinHeap;
		maxHeap<BSTEntry> myMaxHeap;
};
#endif
