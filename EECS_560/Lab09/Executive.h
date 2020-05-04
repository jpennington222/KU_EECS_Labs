/*
 * @Author: Joseph Pennington
 * @File Name: Executive.h
 * @Assignment: EECS 560 Lab 09
 * @Brief: This program is the header file for the Exeuctive Class.
 */

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include <fstream>
#include <iostream>
#include "LeftistHeap.h"
#include "SkewHeap.h"
#include "BinaryNode.h"

class Executive
{
	public:

		/*
		* @pre: None
		* @post: The file name is stored into the private member variable
		* @param Filename: A string represting the file name
		* @return: None
		*/

		Executive(std::string Filename);

		/*
		* @pre: The file name must have been saved
		* @post: Handles all function calls depending on file contents
		* @return: None
		*/

		void run();

		/*
		* @pre: Object made
		* @post: Deletes the object
		* @return: None
		*/

		~Executive();

	private:

		//Filename
		std::string file;

		//Leftist Heaps & Skew Heaps
		LeftistHeap<int, int>* m_left;
		SkewHeap<int, int>* m_skew;

		LeftistHeap<int, int>* m_left1;
		SkewHeap<int, int>* m_skew1;

		LeftistHeap<int, int>* m_left2;
		SkewHeap<int, int>* m_skew2;

		LeftistHeap<int, int>* m_left3;
		SkewHeap<int, int>* m_skew3;

		LeftistHeap<int, int>* m_left4;
		SkewHeap<int, int>* m_skew4;

		LeftistHeap<int, int>* m_left5;
		SkewHeap<int, int>* m_skew5;

};
#endif
