/*
 * File Name: main.cpp
 * Author: Joseph Pennington
 * Assignment: EECS-169 Lab 2 Exercise 6
 * Description: This program will convert an amount in pennies to the amount of change in other coins
 * Date: 9/16/2017
 */


#include <iostream>
int main()
{
int total;
int q;
int d;
int n;
int p;
	std::cout<<"How many pennies do you have? ";
	std::cin>>total;
		q=total/25;
		total=total%25;
		d=total/10;
		total=total%10;
		n=total/5;
		total=total%5;
		p=total;
	std::cout<<"Quarters: "<<q<<'\n';
	std::cout<<"Dimes: "<<d<<'\n';
	std::cout<<"Nickles: "<<n<<'\n';
	std::cout<<"Pennies: "<<p<<'\n';
return(0);
}
