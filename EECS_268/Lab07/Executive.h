/*
 * @Author: Joseph Pennington
 * @File Name: Executive.h
 * @Assignment: EECS 268 Lab 07
 * @Date: 10/30/2018
 * @Brief: This program is the header file for the Exeuctive Class.
 */

 #ifndef EXECUTIVE_H
 #define EXECUTIVE_H
 #include <string>
 #include <fstream>
 #include "bubbleSort.cpp"
 #include "insertionSort.cpp"
 #include "mergesort.cpp"
 #include "quicksort.cpp"
 #include "selectionSort.cpp"
 #include <stdlib.h>
 #include <stdio.h>
 #include <time.h>
 using namespace std;

 class Executive
{
	public:

    /*
		* @pre: none
		* @post: variables are stored
		* @param size: size
    * @param order: random, ascending, descending
    * @param method: type of sort
		* @return: none
		*/

		Executive(int size, string order, string method);

    /*
		* @pre: The contents are saved
		* @post: Handles all function calls depending on choice
		* @return: none
		*/

		void run();

    ~Executive();

	private:
		int m_size;
    string m_order;
    string m_method;
    double time;
    double* m_arr;
};
#endif
