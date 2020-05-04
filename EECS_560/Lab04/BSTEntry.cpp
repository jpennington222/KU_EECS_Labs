/*
 * @Author: Joseph Pennington
 * @File Name: BSTEntry.cpp
 * @Assignment: EECS 560 Lab 04
 * @Brief: This program is the cpp for the BSTEntry class.
 */

#include "BSTEntry.h"

BSTEntry::BSTEntry(std::string movie, float rating)
{
	m_movie = movie;
	m_rating = rating;
}

BSTEntry::BSTEntry()
{
	m_movie;
	m_rating;
}

std::string BSTEntry::getMovie()
{
	return(m_movie);
}

float BSTEntry::getRating()
{
	return(m_rating);
}

void BSTEntry::setMovie(std::string movie)
{
	m_movie = movie;
}

void BSTEntry::setRating(float rating)
{
  m_rating = rating;
}
