/*                                                                              
 * File Name: Exercise4.cpp                                            
 * Author: Joseph Pennington                                                    
 * Assignment: EECS 169 Lab 5 Exercise 4                                        
 * Description: This program will will read values from a file "input.txt" and print the contents, normalize the contents, and reverse the original values                              
 * Date: 10/08/2017                                                              
 */


#include <iostream>
#include <fstream>
int main()
{
	int size = 0;
	double max = 0.0;
	double min = 0.0;
	double* nums=nullptr;
	double normal = 0.0;

	std::ifstream inFile;
	inFile.open("input.txt");
	inFile>>size;
	nums = new double[size];

	for(int i=0; i<size; i++)
	{
		inFile>>nums[i];
	}
	
	std::cout<<"Original array: [";
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

//Sorting for 169

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

//Finished sorting

	std::cout<<"Array sorted in ascending order: [";
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

//Normalization

	std::cout<<"Normalized array: [";
	for(int i=0; i<size; i++)
	{
		 if(nums[i] > max)
        	 {
            	 	max=nums[i];
        	 }
    	}
    	for(int i=0; i<size; i++)
    	{
        	if(nums[i] < max)
        	{
			if((min==0))
			min=nums[i];
			//nums[i] < min

        	}

    	}


	for(int i=0; i<(size-1); i++)
	{
		normal=(nums[i]-min)/(max-min);
		std::cout<<normal<<", ";
	}
	for(int i=(size-1); i<=(size-1); i++)
	{
		normal=(nums[i]-min)/(max-min);
		std::cout<<normal<<"]";
	}
	std::cout<<'\n';
	
//Print reversed array

	std::cout<<"Array sorted in descending order: [";
	for(int i=(size-1); i>=1; i--)
	{
		std::cout<<nums[i]<<", ";
	}
	for(int i=0; i>=0; i--)
	{
		std::cout<<nums[i]<<"]";
	}
	std::cout<<'\n';
	delete[] nums;
	return(0);
}





















	
	
		

