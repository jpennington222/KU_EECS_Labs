/*
 * File Name: fibonacci
 * Author: Joseph Pennington
 * Assignment: EECS 169 Lab 3 Exercise 2
 * Description: This program displays a series of fibonacci numbers that is determined by a user input  
 * Date: 9/24/2017
 */


#include <iostream>
int main()
{
int numbers=0;
int term1=0;
int term2=1;
int termnext=0;

	std::cout<<"How many fibonacci numbers would you like to see?\n";
	std::cin>>numbers;
	std::cout<<"Here is your fibonacci sequence:\n";
	if(numbers==1)
	{
		std::cout<<term1<<'\n';
	}
	else if(numbers==2)
	{
		std::cout<<"0"<<'\n';
		std::cout<<term2<<'\n';
	}
	else
	{
		std::cout<<"0\n";
		std::cout<<"1\n";
		for(int i=2; i<numbers; i++)
		{
			termnext = term2;
			term2 = term1 + term2;
			term1 = termnext;
			std::cout<<term2<<'\n';
		}
	}
return(0);
}
