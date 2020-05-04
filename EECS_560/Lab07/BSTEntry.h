/*
 * @Author: Joseph Pennington
 * @File Name: BSTEntry.h
 * @Assignment: EECS 560 Lab 07
 * @Brief: This program is the h file for the BSTEntry Class
 */

#ifndef BSTENTRY_H
#define BSTENTRY_H
#include <string>

class BSTEntry
{
  public:

    /*
		* @pre: Program ran
		* @post: New BSTEntry made
		* @return: none
		*/

    BSTEntry();

    /*
		* @pre: Program ran
		* @post: New BSTEntry made
    * @param first: First name
    * @param last: Last name
    * @param key: Entry key
		* @return: none
		*/

    BSTEntry(std::string first, std::string last, int key);

    /*
		* @pre: A BSTEntry must be created and filled
		* @post: The first name is found
		* @return: The first name
		*/

    std::string getFirst();

    /*
		* @pre: A BSTEntry must be created and filled
		* @post: The last name is found
		* @return: The last name
		*/

    std::string getLast();

    /*
		* @pre: A BSTEntry must be created and filled
		* @post: The key is found
		* @return: The key name
		*/

    int getKey();

    /*
    * @pre: none
    * @post: The first name is set
    * @param first: The first name
    * @return: none
    */

    void setFirst(std::string first);

    /*
    * @pre: none
    * @post: The last name is set
    * @param last: The last name
    * @return: none
    */

    void setLast(std::string last);

    /*
    * @pre: none
    * @post: The key name is set
    * @param key: The key name
    * @return: none
    */

    void setKey(int key);


  private:

    //First Name
    std::string m_first;

    //Last Name
    std::string m_last;

    //Key
    int m_key;
};
#endif
