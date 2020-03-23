/*                                                                              
 * File Name: WordGuessingGame.cpp                                            
 * Author: Joseph Pennington                                                    
 * Assignment: EECS 169 Lab 5 Exercise 2                                        
 * Description: This program will have the user input an array of strings, and it will print the largest and smallest string
 * Date: 10/09/2017                                                              
 */


#include <iostream>
#include <string>
int main()
{

	int size = 0;
	std::string* array = nullptr;
	std::string max ("\0");
	std::string min ("\0");

	std::cout<<"Input an array size for your words array: ";
	std::cin>>size;
	array = new std::string[size];
	std::cout<<"Now please enter "<<size<<" words\n";

	for(int i=0; i<size; i++)
	{
		std::cout<<"Input a word: ";
		std::cin>>array[i];
	}
	
//Finding smallest an largest word

	for(int i=0; i<size; i++)
	{
		if(array[i].length() > max.length())
		{
			max=array[i];
		}
	}
	min = array[0];
	for(int i=0; i<size; i++)
	{
		if(array[i].length() < min.length())
		{
			min = array[i];
		}
	}

//Max and min found
	
	std::cout<<"The longest word is : "<<max<<'\n';
	std::cout<<"The shortest word is : "<<min<<'\n';

	delete[] array;
	return (0);
}
	
//Usman said during lab I did not need to sort this one for the 169 assignment because it deals with strings//

	
	
	
