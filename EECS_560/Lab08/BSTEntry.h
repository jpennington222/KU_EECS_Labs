/*
 * @Author: Joseph Pennington
 * @File Name: BSTEntry.h
 * @Assignment: EECS 560 Lab 08
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
    * @param name: Name of the game
    * @param key: Integer key
		* @return: none
		*/

    BSTEntry(std::string name, int key);

    /*
		* @pre: A BSTEntry must be created and filled
		* @post: The name is found
		* @return: The name
		*/

    std::string getName();

    /*
		* @pre: A HTE must be created and filled
		* @post: The key is found
		* @return: The key
		*/

    int getKey();

    /*
		* @pre: A HTE must be created
		* @post: The value of the name is stored
		* @param name: Name that is stored
		* @return: none
		*/

    void setName(std::string name);

    /*
		* @pre: A HTE must be created
		* @post: The value of key is stored
		* @param key: Key that is stored
		* @return: none
		*/

    void setKey(int key);


  private:

    //Name of game
    std::string m_name;

    //Key
    int m_key;
};
#endif
