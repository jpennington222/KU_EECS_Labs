/*
 * File Name: main.cpp
 * Author: Joseph Pennington
 * Assignment EECS-169 Lab 2 Exercise 2
 * Description: The program will compute the hypotenuse from to user-inputed values
 * Date: 9/12/2017
 */

#include <math.h>
#include <iostream>
int main(int argc, char** argv) 
{
double a=0;
double b=0;
std::cout<<"Will use the formula a^2 + b^2 = c^2 to solve for the hypotenuse of a triangle.\n";
std::cout<<"Input a value for a: ";
std::cin>>a;
std::cout<<"Input a value for b: ";
std::cin>>b;
std::cout<<"The hypotenuse is : "<<sqrt(a*a + b*b)<<'\n';
return (0);
}

