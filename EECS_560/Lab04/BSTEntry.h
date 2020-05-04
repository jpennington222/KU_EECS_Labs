/*
 * @Author: Joseph Pennington
 * @File Name: BSTEntry.h
 * @Assignment: EECS 560 Lab 04
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
    * @param name: Name of the movie
    * @param rating: Casted value of password of the movie
		* @return: none
		*/

    BSTEntry(std::string movie, float rating);

    /*
		* @pre: A BSTEntry must be created and filled
		* @post: The movie name of the HTE is found
		* @return: The name in the HTE
		*/

    std::string getMovie();

    /*
		* @pre: A HTE must be created and filled
		* @post: The rating of the HTE is found
		* @return: The rating of the HTE
		*/

    float getRating();

    /*
		* @pre: A HTE must be created
		* @post: The value of the HTE name is stored
		* @param name: Name that is stored in the HTE
		* @return: none
		*/

    void setMovie(std::string movie);

    /*
		* @pre: A HTE must be created
		* @post: The value of the HTE rating is stored
		* @param rating: rating that is stored in the HTE
		* @return: none
		*/

    void setRating(float rating);


  private:

    //Name of movie
    std::string m_movie;

    //rating of movie
    float m_rating;
};
#endif
