/*
 * @Author: Joseph Pennington
 * @File Name: Executive.h
 * @Assignment: EECS 268 Lab 03
 * @Date: 09/24/2018
 * @Brief: This program is the header file for the Exeuctive Class. It has the constructure, run, and destructor functions.
 */

 #ifndef EXECUTIVE_H
 #define EXECUTIVE_H
 #include <string>
 #include <fstream>
 #include "StackInterface.h"
 #include "QueueInterface.h"
 #include "Process.h"

 class Executive
{
	public:

    /*
		* @pre: none
		* @post: The file name is stored into the private member variable
		* @param url: A string represting the file name
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
		* @pre: A WebBrowser object must have been made
		* @post: Deletes the WebBrowser object
		* @return: none
		*/

		~Executive();
	private:
		std::string file;
		QueueInterface<Process*>* ProcessQ;
    Process* tempProcess;
};
#endif
