/*
 * File Name: main.cpp
 * Author: Joseph Pennington
 * Assignment: EECS 169 Lab 3 Exercise 1
 * Description: This program will give the user individual ASCII values or a list of ASCII values 33 to 126 inclusively
 * Date: 9/21/2017
 */



#include <iostream>
int main()
{
int choice=0;
int x=0;

	while(1)
	{
		std::cout<<"1) Select a specific number\n";
		std::cout<<"2) Display visible ASCII values (33 to 126)\n";
		std::cout<<"3) Exit\n";
		std::cout<<"Choice ";
		std::cin>>choice;
		if(choice==1)
		{
			std::cout<<"Enter a value: ";
			std::cin>>x;
			std::cout<<x<<" = "<<(char)x<<'\n';
		}
		else if(choice==2)
		{
			for(int x=33; x<=126; x=x+1)
			{
				std::cout<<x<<" = "<<(char)x<<'\n';
			}
		}	
		else if(choice==3)
		{
			std::cout<<"Goodbye...\n";
			break;
		}
		else
		{
		std::cout<<"Invalid Entry\n";
		}
	}
return(0);
}
		

