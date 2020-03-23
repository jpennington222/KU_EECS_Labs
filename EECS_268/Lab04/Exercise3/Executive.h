/*
 * @Author: Joseph Pennington
 * @File Name: Executive.h
 * @Assignment: EECS 268 Lab 04 Exercise 3
 * @Date: 10/01/2018
 * @Brief: This program is the header file for the Exeuctive Class. It has the constructor, run, V, and I functions.
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
		* @post: The flag and number are stored
		* @param Choice: Flag
    * @param Num: Number passed in
		* @return: none
		*/

		Executive(std::string choice, int num);

    /*
		* @pre: The contents are saved
		* @post: Handles all function calls depending on choice
		* @return: none
		*/

		void run();

    /*
     * @pre: Number is saved and flag is -i
     * @post: Recursively finds ith fib number
     * @param num: Number that the user gave
     * @return: Return ith fib num
     */

    int I(int num);

    /*
     * @pre: Number is saved and flag is -v
     * @post: Recursively checks if number is in the fib sequence
     * @param first: First number of sequence that is added to second
     * @param second: Second number that is added the first
     * @checkNum: Number passed by user
     * @return: Return true if in sequence
     */

    bool V(int first, int second, int checkNum);

	private:
		std::string Choice;
    int Num;
};
#endif
