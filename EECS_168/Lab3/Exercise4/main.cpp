/*
 * File Name: main.cpp
 * Author: Joseph Pennington
 * Assignment: EECS 169 Lab 3 Exercise 4
 * Description: The user will input an integer and the program will say if it is prime or not
 * Date: 9/21/2017
 */


#include <iostream>
int main()
{
int value = 0;
bool prime = true;
char next = '\0';
int j = 0;

	while(j>=0)
	{
		std::cout<<"Enter a value: ";
		std::cin>>value;
		if(value<1)
		{
			std::cout<<"Invalid Entry\n";
			break;
		}
		for(int i=2; i<(value/2); i++)
		{
			if(value%i==0)
			{
				prime = false;
			}
		}
		if(prime)
		{
			std::cout<<value<<" is prime\n";
		}
		else
		{
			std::cout<<value<<" is not prime\n";
		}
		std::cout<<"Do you want to quit (y/n): ";
		std::cin>>next;
		if(next=='y')
		{
			std::cout<<"Goodbye...\n";
			break;
		}
		else if(next=='n')
		{
			j++;
		}
	}
return(0);
}
