/*
 * @Author: Joseph Pennington
 * @File Name: HashTableEntry.h
 * @Assignment: EECS 560 Lab 02
 * @Brief: This program is the h file for the HashTableEntry Class
 */

#ifndef HASHTABLEENTRY_H
#define HASHTABLEENTRY_H
#include <string>

class HashTableEntry
{
  public:

    /*
		* @pre: Program ran
		* @post: New HashTableEntry made
		* @return: none
		*/

    HashTableEntry();

    /*
		* @pre: Program ran
		* @post: New HashTableEntry made
    * @param name: Name of the player
    * @param key: goalcount of the player
		* @return: none
		*/

    HashTableEntry(std::string name, int key);

    /*
		* @pre: A HashTableEntry must be created and filled
		* @post: The player name of the HTE is found
		* @return: The name in the HTE
		*/

    std::string getName();

    /*
		* @pre: A HTE must be created and filled
		* @post: The key/goalcount of the HTE is found
		* @return: The key/goalcount of the HTE
		*/

    int getKey();

    /*
		* @pre: A HTE must be created
		* @post: The value of the HTE name is stored
		* @param name: Name that is stored in the HTE
		* @return: none
		*/

    void setName(std::string name);

    /*
		* @pre: A HTE must be created
		* @post: The value of the HTE key is stored
		* @param key: Key/Goalcount that is stored in the HTE
		* @return: none
		*/

    void setKey(int key);
  private:

    //Name of player
    std::string m_name;

    //Goalcount of player
    int m_key;

    //If the entry has been searched (used in rehashing)
    bool searched;

};
#endif
