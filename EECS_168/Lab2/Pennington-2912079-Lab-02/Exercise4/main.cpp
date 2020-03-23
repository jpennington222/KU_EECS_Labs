/* 
 * File Name: main.cpp
 * Author: Joseph Pennington
 * Assignment: EECS-169 Lab 2 Exercise 4
 * Description: This program will cast a user-inputed character to an int
 * Date: 9/12/2017
 */


#include <iostream>
#include <math.h>
int main(int argc, char** argv)
{
char a='\0';
int output=(int)a;

std::cout<<"Input a character: ";
std::cin>>a;
std::cout<<(int)a<<'\n';
return(0);
}
