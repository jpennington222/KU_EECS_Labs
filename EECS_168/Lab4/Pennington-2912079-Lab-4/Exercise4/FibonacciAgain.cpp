/*
 * File Name: FibonacciAgain.cpp
 * Author: Joseph Pennington
 * Assignment: EECS 169 Lab 4 Exercise 4
 * Description: This program will have the user input an integer and the program will print all of the Fibonacci numbers of that size
 * Date: 10/01/2017
 */


#include <iostream>
int main()
{
int digit = 0;
int i = 0;
int j = 0;
int sum1 = 0;
int sum2 = 1;
int sum3 = 0;



while(j>=0)
{	
	std::cout<<"Enter a number of digits: ";
	std::cin>>digit;
	if(digit==1)
	{
		std::cout<<"Here are all "<<digit<<" digit Fibonacci Numbers:\n";
		std::cout<<"0, 1, 2, 3, 5, 8\n";
		break;
	}
	else if(digit==2)
	{
		std::cout<<"Here are all "<<digit<<" digit Fibonacci Numbers:\n";
		for(int i=0; i<100; i++)
		{
			sum1 = sum2;
			sum2 = sum3;
			sum3 = sum1+sum2;
			if(sum2>=10 && sum2<100)
			{
				std::cout<<sum2;
				std::cout<<", ";
			}
		}
		break;
	}
	else if(digit==3)
	{
		std::cout<<"Here are all "<<digit<<" digit Fibonacci Numbers:\n";
		for(int i=0; i<100; i++)
		{
			sum1 = sum2;
			sum2 = sum3;
			sum3 = sum1+sum2;
			if(sum2>=100 && sum2<1000)
			{
				std::cout<<sum2;
				std::cout<<", ";
			}
		}
		break;
	}
	else if(digit==4)
	{
		std::cout<<"Here are all "<<digit<<" digit Fibonacci Numbers:\n";
		for(int i=0; i<100; i++)
		{
			sum1 = sum2;
			sum2 = sum3;
			sum3 = sum1+sum2;
			if(sum2>=1000 && sum2<10000)
			{
				std::cout<<sum2;
				std::cout<<", ";
			}
		}
		break;
	}
	else if(digit==5)
	{
		std::cout<<"Here are all "<<digit<<" digit Fibonacci Numbers:\n";
		for(int i=0; i<100; i++)
		{
			sum1 = sum2;
			sum2 = sum3;
			sum3 = sum1+sum2;
			if(sum2>=10000 && sum2<100000)
			{
				std::cout<<sum2;
				std::cout<<", ";
			}
		}
		break;
	}
	else if(digit==6)
	{
		std::cout<<"Here are all "<<digit<<" digit Fibonacci Numbers:\n";
		for(int i=0; i<100; i++)
		{
			sum1 = sum2;
			sum2 = sum3;
			sum3 = sum1+sum2;
			if(sum2>=100000 && sum2<1000000)
			{
				std::cout<<sum2;
				std::cout<<", ";
			}
		}
		break;
	}
	else if(digit==7)
	{
		std::cout<<"Here are all "<<digit<<" digit Fibonacci Numbers:\n";
		for(int i=0; i<100; i++)
		{
			sum1 = sum2;
			sum2 = sum3;
			sum3 = sum1+sum2;
			if(sum2>=1000000 && sum2<10000000)
			{
				std::cout<<sum2;
				std::cout<<", ";
			}
		}
		break;
	}
	else if(digit==8)
	{
		std::cout<<"Here are all "<<digit<<" digit Fibonacci Numbers:\n";
		for(int i=0; i<100; i++)
		{
			sum1 = sum2;
			sum2 = sum3;
			sum3 = sum1+sum2;
			if(sum2>=10000000 && sum2<100000000)
			{
				std::cout<<sum2;
				std::cout<<", ";
			}
		}
		break;
	}
	else if(digit==9)
	{
		std::cout<<"Here are all "<<digit<<" digit Fibonacci Numbers:\n";
		for(int i=0; i<100; i++)
		{
			sum1 = sum2;
			sum2 = sum3;
			sum3 = sum1+sum2;
			if(sum2>=100000000 && sum2<1000000000)
			{
				std::cout<<sum2;
				std::cout<<", ";
			}
		}
		break;
	}
	else if(digit==10)
	{
		std::cout<<"Here are all "<<digit<<" digit Fibonacci Numbers:\n";
		for(int i=0; i<100; i++)
		{
			sum1 = sum2;
			sum2 = sum3;
			sum3 = sum1+sum2;
			if(sum2>=1000000000 && sum2<10000000000)
			{
				std::cout<<sum2;
				std::cout<<", ";
			}
		}
		break;
	}
	else
	{
		std::cout<<"Invalid entry! Input a value between 1 and 10.\n";
		j++;
	}
}
return (0);
}
		
	
