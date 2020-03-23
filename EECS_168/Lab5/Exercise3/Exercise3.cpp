/*                                                                              
 * File Name: Exercise3.cpp                                            
 * Author: Joseph Pennington                                                    
 * Assignment: EECS 169 Lab 5 Exercise 3                                        
 * Description: This program will read a file "input.txt" and print the contents of that file                              
 * Date: 10/08/2017                                                              
 */


#include <iostream>
#include <fstream>
int main()
{
	int size = 0;
	double* nums=nullptr;

	std::ifstream inFile;
	inFile.open("input.txt");
	inFile>>size;
	nums = new double[size];

	for(int i=0; i<size; i++)
	{
		inFile>>nums[i];
	}

//sorting for 169
	
	double sorted = 0.0;	
	for (int i = 0; i < size; i++)
	{
		for (int j =i+1; j < size; j++)
		{
			if (nums[i] > nums[j])
			{
				sorted=nums[i];
				nums[i]=nums[j];
				nums[j]=sorted;
			}
		}
	}

//finished sorting

	std::cout<<"Contents of input.txt in ascending order: \n";
	std::cout<<"[";
	for(int i=0; i<size; i++)
	{    
		for(i=0; i<(size-1); i++)
		{
			std::cout<<nums[i]<<", ";
		}
		for(i=(size-1); i<=(size-1); i++)
		{
			std::cout<<nums[i]<<"]";
		}
	}
	std::cout<<'\n';
	delete[] nums;
	return (0);
}
