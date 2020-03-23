/*                                                                              
 * @Author: Joseph Pennington
 * @File Name: Executive.h 
 * @Assignment: EECS 268 Lab 02
 * @Date: 09/17/2018
 * @Brief: This program is the header file for the Exeuctive Class.
 */

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>
#include <fstream>
#include <stdexcept>
#include "WebBrowser.h"
#include "WebBrowserInterface.h"
#include "ListInterface.h"

class Executive
{
	public:
		Executive(std::string Filename);
		/*
		* @pre: none
		* @post: The file name is stored into the private member variable
		* @param url: A string represting the file name
		* @return: none
		*/

		void run();
	
		/*
		* @pre: The file name must have been saved
		* @post: Handles all function calls depending on file contents
		* @return: none
		*/

		~Executive();

		/*
		* @pre: A WebBrowser object must have been made
		* @post: Deletes the WebBrowser object
		* @return: none
		*/

	private:
		std::string file;
		WebBrowserInterface* history;
};
#endif
