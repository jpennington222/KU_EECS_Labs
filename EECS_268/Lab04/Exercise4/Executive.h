/*
 * @Author: Joseph Pennington
 * @File Name: Executive.h
 * @Assignment: EECS 268 Lab 03
 * @Date: 09/24/2018
 * @Brief: This program is the header file for the Exeuctive Class. It has the constructor, run, isBalanced,  and destructor functions.
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
		* @post: array is created
		* @param Input: A string represting the parenthesis
		* @return: none
		*/

		Executive(std::string Input);

    /*
    * @pre: The array must have been created
		* @post: Prints results of isBlanced
		* @return: none
		*/

		void run();

    /*
     * @pre: An array of the input string must have been made
     * @post: Deletes the array object
     * @param array: Array with parenthesis
     * @param i: Initial position
     * @param j: Ending position
     * @return: none
     */

    bool isBalanced(char* array, int i, int j);

		~Executive();
	private:
		std::string input;
    int size;
    char* m_array;
    char* new_array;
    int new_size;
};
#endif
