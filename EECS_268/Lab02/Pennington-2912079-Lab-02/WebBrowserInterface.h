/*                                                                              
 * @Author: Joseph Pennington
 * @File Name: WebBrowserInterface.h
 * @Assignment: EECS 268 Lab 02
 * @Date: 09/17/2018
 * @Brief: This program is the header file for the Web Browser Simulator Class. It declares the destructor, navigateTo, foward, back, currentURL. and copyCurrentHistory
 */

#ifndef WEBBROWSERINTERFACE_H
#define WEBBROWSERINTERFACE_H
#include "ListInterface.h"
#include <string>

class WebBrowserInterface
{
	public:
		virtual ~WebBrowserInterface(){}
		
		/*
		* @pre: none
		* @post: All memory allcated by the implementing class should be freed
		* @return: none
		*/

		virtual void navigateTo(std::string url) = 0;

		/*
		* @pre: none
		* @post: The browser navigates to the given URL
		* @param url: A string represting the URL
		* @return: none
		*/

		virtual void forward() = 0;

		/*
		* @pre: none
		* @post: If possible, the browser navigates foward in the history, otherwise it keeps focus
		* @return: none
		*/
		   
		virtual void back() = 0;

		/*
		* @pre: none
		* @post: If possible, the browser navigates backwards in the history, otherwise it keeps focus
		* @return: none
		*/

		virtual std::string currentURL() const = 0;

		/*
		* @pre: none
		* @post: Finds the current URL
		* @return: Returns tha current URL as a string
		*/

		virtual void copyCurrentHistory(ListInterface<std::string>& destination) = 0;

		/*
		* @pre: The list being passed in is empty
		* @post: The current browser histry is copued into the given list
		* @param destination: An emptry list of strings that will have a copy of current history copied into
		* @return: none
		*/
};

#endif
