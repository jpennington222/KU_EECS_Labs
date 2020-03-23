/* File Name: main.cpp
 * Author: Joseph Pennington
 * Assignment: EECS-169 Lab2
 * Description: This program will convert the input temperatre from Fahrenheit to Celsius
 * Date: 9/12/2017
 */


#include <iostream>
int main(int argc, char** argv)
{
double fahrenheit=0;
std::cout<<"Enter the temperature in Fahrenheit: ";
std::cin>>fahrenheit;
std::cout<<fahrenheit<<" degrees Fahrenheit= "<<((fahrenheit - 32) * 0.5556)<< " degrees Celsius"<<'\n';
return (0);
}
