/*
 * @Author: Joseph Pennington
 * @File Name: Executive.h
 * @Assignment: EECS 560 Lab 10
 * @Brief: This program is the header file for the Exeuctive Class.
 */

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include <fstream>
#include <iostream>
#include "Graph.h"
#include "DisjointSet.h"
#include <limits>

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
		* @pre: Heaps made
		* @post: Deletes the object
		* @return: none
		*/

		~Executive();

	private:

		//Filenames
		std::string file1;
		std::string file2;

		//Disjoint Set pointer
		DisjointSet* m_disjointSet;

		//Matrix pointer
		int** m_arr;

		//Size of graph
		int m_size;

		//Graph pointer
		Graph* m_graph;

		//Names of dinosaurs
		std::string m_names[50];
};
#endif
