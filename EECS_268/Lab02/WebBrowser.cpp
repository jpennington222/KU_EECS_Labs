/*                                                                              
 * @Author: Joseph Pennington
 * @File Name: WebBrowser.cpp 
 * @Assignment: EECS 268 Lab 02
 * @Date: 09/17/2018
 * @Brief: This program is the cpp file for the WebBrowser Class. It contains the constructor, navigateTo, forward, back, currentURL, copyCurrentHistory, and the descructor functions.
 */

#include "WebBrowser.h"
#include "LinkedList.h"
#include "ListInterface.h"
#include "WebBrowserInterface.h"
#include "Node.h"
#include <string>
#include <stdexcept>
#include <iostream>

WebBrowser::WebBrowser()
{
	history = new LinkedList<std::string>();
	m_current = 0;
}

void WebBrowser::navigateTo(std::string url)
{
	if(m_current == history -> getLength())
	{
		try
		{
			history -> insert(m_current+1, url);
		}
		
		catch(std::runtime_error error)
		{
			std::cout<<error.what()<<'\n';
		}
		
		m_current++;
	}

	else
	{
		for(int i=history -> getLength(); i>m_current; i--)
		{
			try
			{
				history -> remove(i);
			}
			
			catch(std::runtime_error error)
			{
				std::cout<<error.what()<<'\n';
			}
		}

		try
		{
			history -> insert(m_current+1, url);
		}

		catch(std::runtime_error error)
		{
			std::cout<<error.what()<<'\n';
		}

		m_current++;
	}
}

void WebBrowser::forward()
{
	if(m_current != history -> getLength())
	{
		m_current++;
	}
}

void WebBrowser::back()
{
	if(m_current != 1)
	{
		m_current--;
	}
}

std::string WebBrowser::currentURL()const
{
	try
	{
		return(history -> getEntry(m_current));
	}

	catch(std::runtime_error error)
	{
		std::cout<<error.what()<<'\n';

	}
}

void WebBrowser::copyCurrentHistory(ListInterface<std::string>& destination)
{
	for(int i=1; i<=(history -> getLength()); i++)
	{
		try
		{
			destination.insert(i, history -> getEntry(i));
		}
		
		catch(std::runtime_error error)
		{
			std::cout<<error.what()<<'\n';
		}
	}
}

WebBrowser::~WebBrowser()
{
	delete history;
}














			
