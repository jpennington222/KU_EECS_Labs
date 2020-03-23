/*                                                                              
 * File Name: Exercise1.cpp                                            
 * Author: Joseph Pennington                                                    
 * Assignment: EECS 169 Lab 5 Exercise 1                                        
 * Description: This program will have the user input 5 values into an array, and the program will list the values, add, find the average, say the biggest value, and say the smallest value                              
 * Date: 10/04/2017                                                              
 */


#include <iostream>
int main()
{
	double nums[5];
    
	std::cout<<"Please enter 5 numbers\n";
	for(int i=0; i<5; i++)
	{
		std::cout<<"Input a number into your array: ";
		std::cin>>nums[i];
        
	}
	std::cout<<"Here are all of the numbers in your array: \n";
	std::cout<<nums[0]<<'\n';
	std::cout<<nums[1]<<'\n';
	std::cout<<nums[2]<<'\n';
	std::cout<<nums[3]<<'\n';
	std::cout<<nums[4]<<'\n';
    
//sorting the array

	double smallestindex = 0.0;
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
    		{
        		if(nums[j] > nums[j+1])
        		{
           			smallestindex = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = smallestindex;
        		}
		}
	}

//printing the array sorted

	std::cout<<"Here are all of the numbers sorted in ascending order in your array: \n";
	for(int j=0; j<5; j++)
	{
		std::cout<<nums[j]<<'\n';
	}
	
	std::cout<<"The sum of all the values is: "<<nums[0]+nums[1]+nums[2]+nums[3]+nums[4]<<'\n';
	std::cout<<"The average of all the values is: "<<(nums[0]+nums[1]+nums[2]+nums[3]+nums[4])/5<<'\n';
	
	std::cout<<"The largest value is : "<<nums[4]<<'\n';
	std::cout<<"The smallest value is : "<<nums[0]<<'\n';
	return (0);
}








