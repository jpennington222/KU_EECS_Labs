/*                                                                              
 * File Name: Pyramid.cpp                                            
 * Author: Joseph Pennington                                                    
 * Assignment: EECS 169 Lab 4 Exercise 3                                        
 * Description: This program will have the user input an int and the program will make a pyramid with a base of that int                                   
 * Date: 9/26/2017                                                              
 */

#include <iostream>
int main()
{
	int base=0;

	std::cout<<"Enter the number of asterisks for the base of the triangle: ";
	std::cin>>base;
	for(int i=1; i<=base; i++)
	{
		for(int j=1; j<=i; j++)
		{
			std::cout<<"*";
		}
		std::cout<<'\n';
	}
	return (0);
}

