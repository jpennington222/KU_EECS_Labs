/*
 * @Author: Joseph Pennington
 * @File Name: Executive.h
 * @Assignment: EECS 268 Lab 05
 * @Date: 10/08/2018
 * @Brief: This program is the header file for the Executive Class. It has the constructor, run, isValid, floodRec, getters, and the destructor functions.
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
		* @post: The input string is stored into the private member variable and each variable
		* @param Input: String that is the input
		* @return: none
		*/

		Executive(std::string file);

    /*
		* @pre: The string and variables must be saved
		* @post: Handles passing array to recursive function
		* @return: none
		*/

		void run();

    /*
		* @pre: Map is saved
		* @post: Determines if move is valid
		* @param row: Row in map
    * @param col: Col in map
		* @return: True if valid move and false if not valid
		*/

		bool isValid(int row, int col);

    /*
    * @pre: Map is saved
    * @post: Recursively adds water to map
    * @param row: Row in map
    * @param col: Col in map
    * @return: True if map is fully flooded and false if water runs out
    */

		bool floodRec(int row, int col);

    /*
		* @pre: The string and variables must be saved
		* @post: Gets row total
		* @return: Row total
		*/

		int getRow();

    /*
		* @pre: The string and variables must be saved
		* @post: Gets column total
		* @return: Column total
		*/

		int getCol();

    /*
		* @pre: The string and variables must be saved
		* @post: Gets starting row
		* @return: Starting row
		*/

		int getStartR();

    /*
		* @pre: The string and variables must be saved
		* @post: Gets starting column
		* @return: Starting column
		*/

		int getStartC();

    /*
		* @pre: Executive object has been created
		* @post: Deletes object
		* @return: none
		*/

    ~Executive();

  private:
    std::string Filename;
    int m_row;
    int m_col;
    int m_startR;
    int m_startC;
    int water;
    char** m_map;
};
#endif
