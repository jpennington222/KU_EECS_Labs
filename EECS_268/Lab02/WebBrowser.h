/*                                                                              
 * @Author: Joseph Pennington
 * @File Name: WebBrowser.h
 * @Assignment: EECS 268 Lab 02
 * @Date: 09/17/2018
 * @Brief: This program is the h file for the WebBrowser Class
 */

#ifndef WEBBROWSER_H
#define WEBBROWSER_H
#include "WebBrowserInterface.h"
#include "ListInterface.h"
#include "LinkedList.h"
#include <string>
#include <iostream>

class WebBrowser : public WebBrowserInterface
{
	public:
		WebBrowser();

		/*
		* @pre: None
		* @post: WebBrowser is made
		* @return: none
		*/

		void navigateTo(std::string url);

		/*
		* @pre: A WebBrowser must be created
		* @post: The URL is saved and navigated to
		* @param url: The URL that is being saved
		* @return: none
		*/

		void forward();

		/*
		* @pre: A WebBrowser must be created
		* @post: The Browser is advanced forward
		* @return: none
		*/

		void back();

		/*
		* @pre: A WebBrowser must be created
		* @post: The Browser is navigated backwards
		* @return: none
		*/

		std::string currentURL()const;

		/*
		* @pre: A WebBrowser must be created
		* @post: The current URL in the Browser is fuond
		* @return: String URL
		*/

		void copyCurrentHistory(ListInterface<std::string>& destination);

		/*
		* @pre: A WebBrowser must be created
		* @post: A copy of the Browser is made
		* @param destination: Where the Browser is being copied
		* @return: none
		*/

		~WebBrowser();

		/*
		* @pre: A WebBrowser must be created
		* @post: the Browser is deleted
		* @return: none
		*/

	private:
		ListInterface<std::string>* history;
		int m_current;
};
#endif
