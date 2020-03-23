/*                                                                              
 * File Name: Exercise1.cpp                                            
 * Author: Joseph Pennington                                                    
 * Assignment: EECS 169 Lab 6 Exercise 1                                        
 * Description: This program will give the user a choice to insert a value into an array, remove a value from an array, count how many times a value is an the array, check for a palindrome, and print the array
 * Date: 10/10/2017                                                              
 */


#include <iostream>

int* insert(int arr[], int size, int value, int position);
int* remove(int arr[], int size, int position);
int count(int arr[], int size, int target);
bool isPalindrome(int arr[], int size);
void print(int arr[], int size);

int main()
{
	int choice = 0;
	int size = 0;
	int value = 0;
	int position = 0;
	int target = 0;
	int* myarr=nullptr;
	

	std::cout<<"Input size of the array: ";
	std::cin>>size;
	myarr=new int[size];

	if(size>0)
	{
		for(int i=0; i<size; i++)
		{
			std::cout<<"Input a number: ";
			std::cin>>value;
			myarr[i]=value;
		}
	}
	else
	{
		std::cout<<"Invalid entry. Input a number: ";
	}
	
	while(choice != 6)
	{

		std::cout<<"Make a selection:\n";
		std::cout<<"1) Insert\n";
		std::cout<<"2) Remove\n";
		std::cout<<"3) Count\n";
		std::cout<<"4) Check palindrome\n";
		std::cout<<"5) Print\n";
		std::cout<<"6) Exit\n";
		std::cout<<"Choice: ";
		std::cin>>choice;
	
		if(choice==1)
		{
			while(1)
			{
				std::cout<<"Position of new value: ";
				std::cin>>position;
				if(position>=size)
				{
					std::cout<<"That posisition is outside of the range\n";
				}
				else if(position<size && position>=0)
				{
					break;
				}
				else
				{
					std::cout<<"Invalid Entry\n";
				}
			}
			std::cout<<'\n';
			std::cout<<"Input new value: ";
			while(1)
			{
				std::cin>>value;
				if(value>=0)
				{
					break;
				}
				else
				{
					std::cout<<"Invalid Entry\n";
				}
			}
			int* temp=nullptr;
			temp = insert(myarr, size, value, position);
			delete[] myarr;
			myarr=temp;
			size++;
		}
		else if(choice==2)
		{
			while(1)
			{
				std::cout<<"Position of value to remove: ";
				std::cin>>position;
				if(position>=size)
				{
					std::cout<<"That posisition is outside of the range\n";
				}
				else if(position<size && position>=0)
				{
					break;
				}
				else
				{
					std::cout<<"Invalid Entry\n";
				}
			}
			std::cout<<'\n';
			int* temp=nullptr;
			temp = remove(myarr, size, position);

			delete[] myarr;
			myarr=temp;
			size--;
		}
		else if(choice==3)
		{
			while(1)
			{
				std::cout<<"Input a number to check if it is in the array: ";
				std::cin>>target;
				if(value>=0)
				{
					break;
				}
				else
				{
					std::cout<<"Invalid Entry\n";
				}
			}
			count(myarr, size, target);
		}
		else if(choice==4)
		{
			if(isPalindrome(myarr, size)==true)
			{
				std::cout<<"The array is a palindrome\n";
			}
			else if(isPalindrome(myarr, size)==false)
			{
				std::cout<<"The array is not a palindrome\n";
			}
		}
		else if(choice==5)
		{
			print(myarr, size);
		}
		else if(choice==6)
		{
			std::cout<<"Goodbye\n";
			break;
		}
		else
		{
			std::cout<<"Invalid Entry\n";
		}
	}
	delete[] myarr;	
	return (0);
}	


//1
int* insert(int arr[], int size, int value, int position)
{
	int* temp = new int[size+1];
	for(int i=0; i<size+1; i++)
	{
		if(i<position)
		{
			temp[i] = arr[i];
		}
		if(i==position)
		{
			temp[position] = value;
		}
		if(i>position)
		{
			temp[i] = arr[i-1];
		}
	}
	return temp;
}


//2
int* remove(int arr[], int size, int position)
{
	int* temp = new int[size-1];
	for(int i=0; i<size; i++)
	{
		if(i<position)
		{
			temp[i] = arr[i];
		}
		else if(i>position)
		{
		temp[i-1] = arr[i];
		}
	}
	return temp;
}


//3
int count(int arr[], int size, int target)
{
	int count = 0;
	for(int i=0; i<size; i++)
	{
		if(arr[i]==target)
		{
			count++;
		}
	}
	std::cout<<target<<" is in the array "<<count<<" time(s)\n";
	return (count);
}


//4
bool isPalindrome(int arr[], int size)
{
	int i = 0;
	int x = 0;
	while(x==0 && i<size)
	{
		if(arr[i] == arr[size-i-1])
		{
			x = 0;
			i++;
		}
		else
		{
			x = 1;
		}

	}
	if(x==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//5
void print(int arr[], int size)
{
	std::cout<<"[";
	for(int i=0; i<(size-1); i++)
	{
		std::cout<<arr[i]<<", ";
	}
	for(int i=(size-1); i<=(size-1); i++)
	{
		std::cout<<arr[i]<<"]";
	}
	std::cout<<'\n';
}

































	
	
		
