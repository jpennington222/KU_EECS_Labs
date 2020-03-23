/*
 * File Name: main.cpp
 * Author: Joseph Pennington
 * Assignment: EECS 169 Lab 3 Exercise 3
 * Description: The user will input an integer and the program will say if it is a fibonacci number or not
 * Date: 9/21/2017
 */


#include <iostream>
int main()
{
    int value = 0;
    int sum1 = 0;
    int sum2 = 1;
    int sum3 = 0;
    int count = 1;
    
    std::cout<<"Enter a value: ";
    std::cin>>value;
    if(value==0)
    {
        std::cout<<"0 is the 1st value in the Fibonacci Sequence!\n";
        std::cout<<"Goodbye\n";
    }
    else if(value==1)
    {
        std::cout<<"1 is the 2nd and 3rd values in the Fibonacci Sequence!\n";
        std::cout<<"Goodbye\n";
    }
    else
    {
        for(int i=2;sum3 <= value; i++)
        {
            
            if(sum3==value)
            {
                std::cout<<value<<" is the "<<count<<"th value in the Fibonacci Sequence!\n";
                std::cout<<"Goodbye\n";
		break;
	    }
            

	     sum1 = sum2;
             sum2 = sum3;
             sum3 = sum1+sum2;
             count = count + 1;

            if(sum3>value)
            {
                std::cout<<value<<" is not in the Fibonacci Sequence!\n";
                std::cout<<"Goodbye\n";
                break;
            }
	     
        }
    }
    return (0);
}

