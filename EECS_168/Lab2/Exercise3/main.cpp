/*
 * File Name: main.cpp
 * Author: Joseph Pennington
 * Assignment: EECS-169 Lab 2 Exercise 3
 * Description: This program will give the roots to a quadratic equation from user-inputed values  	for a, b, and c
 * Date: 9/12/2017
 */

#include <iostream>
#include <math.h>
int main(int argc, char** argv)
{
double a=0.0;
double b=0.0;
double c=0.0;

std::cout<<"Input a: ";
std::cin>>a;
std::cout<<"Input b: ";
std::cin>>b;
std::cout<<"Input c: ";
std::cin>>c;
std::cout<<"root 1: "<<((-b+sqrt(b*b-4.0*a*c))/(2.0*a))<<'\n';
std::cout<<"root 2: "<<((-b-sqrt(b*b-4.0*a*c))/(2.0*a))<<'\n';
return (0);

}
