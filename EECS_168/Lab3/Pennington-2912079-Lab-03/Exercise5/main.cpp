/*
 * File Name: main.cpp
 * Author: Joseph Pennington
 * Assignment: EECS 169 Lab 3 Exercise 5
 * Description: The user will input an integer that the program will use to find what nth prime number it is
 * Date: 9/24/2017
 */


#include <iostream>
int main()
{
int value = 0;
int number = 0;
int a = 0;


std::cout<<"Input a number: ";
std::cin>>value;
if(value<=0)
{
	std::cout<<"Invalid Entry. Only numbers between 1 and 100.\n";
}
else if(value>=101)
{
	std::cout<<"Invalid Entry. Only numbers between 1 and 100.\n";
}
else if(value==1)
{
	std::cout<<"2 is the 1st prime number\n";
}
else if(value==2)
{
	std::cout<<"3 is the 2nd prime number\n";
}
else if(value==3)
{
	std::cout<<"5 is the 3rd prime number\n";
}
else if(value>=4)
{
	for(int i=2; i<=500000; i++)
	{
		number = 0;
		for(int j=2; j<=(i/2); j++)
		{
			if(i%j==0)
			{
				number = 1;
				break;
			}
		}
	if(number==0)
	{
		a++;
		if(a==value)
		{
			std::cout<<i<<" is the "<<value<<"th prime number"<<'\n';
			break;
		}
	}
}
}
return (0);
}

		
	

