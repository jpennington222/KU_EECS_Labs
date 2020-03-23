/*                                                                              
 * File Name: ArrayHelper.cpp                                            
 * Author: Joseph Pennington                                                    
 * Assignment: EECS 169 Lab 7 Exercise 1                                        
 * Description: This program will read in data from a file and use functions to print the 2D array, find the sum and average of the 1D arrays and 2D array, and find the maximum value of the values
 * Date: 10/24/2017                                                              
 */

#include <iostream>
#include <fstream>
#include <string>

void print2DArray(int** array, int rows, int cols);
int arraySum(int* array, int size);
double arrayAvg(int* array, int size);
int arraySum2D(int** array, int rows, int cols);
double arrayAvg2D(int** array, int rows, int cols);
int arrayMax2D(int** array, int rows, int cols);
int** arrayFromFile(std::string fileName, int& numRows, int& numCols);
void transpose(int** array, int rows, int cols);

int main( int argc, char* argv[] )
{
	std::string fileName;
	if(argc > 1)
	{
		fileName = argv[1];
	}

	int numRows = 0;
	int numCols = 0;
	double avg = 0.0;
	int sum = 0;
	int max = 0;
	int** grid = nullptr;

	grid = arrayFromFile(fileName, numRows, numCols);

	print2DArray(grid, numRows, numCols);
	


	std::cout<<'\n';
	
	for(int i=0; i<numRows; i++)
	{
		std::cout<<"row "<<i<<" sum = "<<arraySum(grid[i], numCols)<<", ";
		std::cout<<"avg = "<<arrayAvg(grid[i], numCols);
		std::cout<<'\n';
	}

	
	max = arrayMax2D(grid, numRows, numCols);
	std::cout<<"The largest value in the array is = "<<max<<'\n';

	sum = arraySum2D(grid, numRows, numCols);
	std::cout<<"The sum for the entire array is = "<<sum<<'\n';
	
	avg = arrayAvg2D(grid, numRows, numCols);
	std::cout<<"The average for the entire array is = "<<avg<<'\n';
	
	if(numRows==numCols)
	{
		transpose(grid, numRows, numCols);
	}
	else if(numRows != numCols)
	{
		std::cout<<"Cannot transpose this array\n";
	}
	
	for(int i=0; i<numRows; i++)
	{
		delete[] grid[i];
	}
	delete[] grid;
	return(0);
}



//Print 2D array
void print2DArray(int** array, int rows, int cols)
{
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<(cols-1); j++)
		{
			std::cout<<array[i][j]<<", ";
		}
		for(int j=(cols-1); j<cols; j++)
		{
			std::cout<<array[i][j];
		}
		std::cout<<'\n';
	}
}


//Sum of 1D arrays
int arraySum(int* array, int size)
{
	int sum = 0;
	
	for(int i=0; i<size; i++)
	{
		sum = sum + array[i];
	}
	return sum;
}


//Average of 1D arrays
double arrayAvg(int* array, int size)
{
	double sum = 0.0;
	double avg = 0.0;

	for(int i=0; i<size; i++)
	{
		sum = sum + array[i];
	}
	avg = sum/size;
	return avg;
}


//Max value of 2D array
int arrayMax2D(int** array, int rows, int cols)
{
	int min=array[0][0];
	int max = min;

	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			if(array[i][j]<min)
			{
				min = array[i][j];
			}
			else if(array[i][j]>max)
			{
				max = array[i][j];
			}
		}
	}
	return max;
}


//Sum of 2D array
int arraySum2D(int** array, int rows, int cols)
{
	int sum = 0;
	
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			sum = sum + array[i][j];
		}
	}
	return sum;
}


//Average of 2D array
double arrayAvg2D(int** array, int rows, int cols)
{
	double sum = 0;
	int totalnums = 0;
	double avg = 0.0;
	
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			sum = sum + array[i][j];
		}
	}
	totalnums = rows * cols;
	avg = sum/totalnums;
	return avg;
}


//transpose
void transpose(int** array, int rows, int cols)
{
	for(int j=0; j<cols; j++)
	{
		for(int i=0; i<rows; i++)
		{
			std::cout<<array[i][j]<<" ";
		}
		std::cout<<'\n';
	}
}


//Data from text
int** arrayFromFile(std::string fileName, int& numRows, int& numCols)
{

	std::ifstream inFile;
	inFile.open (fileName);

	inFile>>numRows;
	inFile>>numCols;

	int** grid = nullptr;
	grid = new int*[numRows];
	
	for(int i=0; i<numRows; i++)
	{
		grid[i] = new int[numCols];
	}

	for(int i=0; i<numRows; i++)
	{
		for(int j=0; j<numCols; j++)
		{
			inFile>>grid[i][j];
		}
	}
	return grid;
}
	




















