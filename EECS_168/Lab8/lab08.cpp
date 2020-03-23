/*                                                                              
 * File Name: lab08.cpp                                            
 * Author: Joseph Pennington                                                    
 * Assignment: EECS 169 Lab 8 Exercise 1                                        
 * Description: This program will read a 2D array from a file, count the amount of crosses in that file, and give the center location of the cross 
 * Date: 11/1/2017                                                              
 */

#include <fstream>
#include <string>
#include <iostream>

char** arrayFromFile(std::string fileName, int& rows, int& cols);
int main( int argc, char* argv[] )
{
	std::string fileName;
	std::string mode;
	if(argc > 1)
	{
		fileName = argv[1];
		mode = argv[2];
	}
	
	int rows = 0;
	int cols = 0;
	int count = 0;
	char** cross = nullptr;

	cross = arrayFromFile(fileName, rows, cols);


//Exercise 1
	if(mode == "-e")
	{
		std::cout<<"sample.txt contains ";
		for(int i=1; i<rows-1; i++)
		{
			for(int j=1; j<cols-1; j++)
			{
				if(cross[i][j] == '+')
				{
					if(cross[i][j+1] == '+' && cross[i+1][j] == '+' && cross[i][j-1] == '+' && cross[i-1][j] == '+')
					{
						count++;
						cross[i][j] = 'c';
						cross[i][j+1] = '!';
						cross[i+1][j] = '!';
						cross[i][j-1] = '!';
						cross[i-1][j] = '!';
					}
				}
			}
		}
		std::cout<<count<<" crosses.\n";
		std::cout<<"Location(s) of center(s): \n";
		for(int i=1; i<rows-1; i++)
		{
			for(int j=1; j<cols-1; j++)
			{
				if(cross[i][j] == 'c')
				{
					std::cout<<"("<<i<<","<<j<<")\n";
				}
			}
		}				

		for(int i=0; i<rows; i++)
		{
			delete[] cross[i];
		}
		delete[] cross;
	}

//Exercise 2
	else if(mode == "-f")
	{
		std::cout<<"sample.txt contains ";
		for(int i=1; i<rows-1; i++)
		{
			for(int j=1; j<cols-1; j++)
			{
				if(cross[i][j] == '+')
				{
					if(cross[i][j+1] == '+' && cross[i+1][j] == '+' && cross[i][j-1] == '+' && cross[i-1][j] == '+')
					{
						count++;
						cross[i][j] = 'c';
					}
				}
			}
		}
		std::cout<<count<<" crosses.\n";
		std::cout<<"Location(s) of center(s): \n";
		for(int i=1; i<rows-1; i++)
		{
			for(int j=1; j<cols-1; j++)
			{
				if(cross[i][j] == 'c')
				{
					std::cout<<"("<<i<<","<<j<<")\n";
				}
			}
		}				
		for(int i=0; i<rows; i++)
		{
			delete[] cross[i];
		}
		delete[] cross;
	}
	return(0);
}	

char** arrayFromFile(std::string fileName, int& rows, int& cols)
{

	std::ifstream inFile;
	inFile.open (fileName);

	inFile>>rows;
	inFile>>cols;

	char** cross = nullptr;
	cross = new char*[rows];
	
	for(int i=0; i<rows; i++)
	{
		cross[i] = new char[cols];
	}

	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			inFile>>cross[i][j];
		}
	}
	inFile.close ();
	return cross;
}
