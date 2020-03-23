/*
 * @Author: Joseph Pennington
 * @File Name: Executive.h
 * @Assignment: EECS 268 Lab 04 Exercise 2
 * @Date: 10/01/2018
 * @Brief: This program is the header file for the Exeuctive Class. It has the constructor, run, permute, and destructor functions.
 */

 #ifndef EXECUTIVE_H
 #define EXECUTIVE_H
 #include <string>
 #include <fstream>

 class Executive
{
	public:

    /*
		* @pre: none
		* @post: The input string is stored into the private member variable
		* @param Input: String that is the input
		* @return: none
		*/

		Executive(std::string Input);

    /*
		* @pre: The string must be saved
		* @post: Handles passing string to recursive function
		* @return: none
		*/

		void run();

    /*
     * @pre: A string is passed in
     * @post: Recursively permutes the string
     * @Param Front: Empty string passed in that is added to
     * @param Back: String that is added to front 
     * @return: none
     */

    void permute(std::string Front, std::string Back);
	private:
		std::string input;
    int size;
};
#endif
