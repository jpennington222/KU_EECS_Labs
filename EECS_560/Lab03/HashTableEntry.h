/*
 * @Author: Joseph Pennington
 * @File Name: HashTableEntry.h
 * @Assignment: EECS 560 Lab 03
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
    * @param name: Name of the user
    * @param key: Casted value of password of the user
		* @return: none
		*/

    HashTableEntry(std::string name, std::string password, int key);

    /*
		* @pre: A HashTableEntry must be created and filled
		* @post: The user name of the HTE is found
		* @return: The name in the HTE
		*/

    std::string getName();

    /*
		* @pre: A HTE must be created and filled
		* @post: The key of the HTE is found
		* @return: The key of the HTE
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
		* @param key: Key that is stored in the HTE
		* @return: none
		*/

    void setKey(int key);

    /*
		* @pre: A HashTableEntry must be created and filled
		* @post: The password of the HTE is found
		* @return: The password in the HTE
		*/

    std::string getPassword();

    /*
		* @pre: A HTE must be created and filled
		* @post: The searched value of the HTE is found
		* @return: The searched value of the HTE
		*/

    bool getSearched();

    /*
		* @pre: A HTE must be created
		* @post: The value of the HTE password is stored
		* @param name: Password that is stored in the HTE
		* @return: none
		*/

    void setPassword(std::string password);

    /*
		* @pre: A HTE must be created
		* @post: The value of the HTE searched is stored
		* @param key: Searched value that is stored in the HTE
		* @return: none
		*/

    void setSearched(bool searched);
  private:

    //Name of user
    std::string m_name;

    //Key of user
    int m_key;

    //Password of user
    std::string m_password;

    //If the entry has been searched
    bool m_searched;

};
#endif
