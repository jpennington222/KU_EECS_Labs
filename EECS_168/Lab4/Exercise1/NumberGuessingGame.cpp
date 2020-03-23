/*
 * File Name: NumberGuessingGame.cpp
 * Author: Joseph Pennington
 * Assignment: EECS 169 Lab 4 Exercise 1
 * Description: This program will have the user guess a random number and the program will say if it is too high or too low.
 * Date: 10/01/2017
 */



#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
int guess = 0;
int count = 1;
int random = 0;
int x = 0;
int y = 0;
int i = 0;
int j = 0;
int k = 0;
char next = '\0';

	srand( time(NULL) );
	random = rand() % 100 + 1;
	std::cout<<"Welcome to the number guessing game.\n";
	
	do{
		std::cout<<"Guess a number: ";
		std::cin>>guess;
		if(guess>random)
		{
			y=((guess)-(random));
			i=guess;
			std::cout<<"Sorry, your guess was too high.\n";
			count=count+1;
			j++;
		}
		else if(guess<random)
		{
			x=((random)-(guess));
			std::cout<<"Sorry, your guess was too low.\n";
			j=guess;
			count=count+1;
			k++;
		}
		else if(guess == random)
		{
			std::cout<<"You win!\n";
			std::cout<<"You guessed the secret number after "<<count<<" guess(es).\n";
			if(x>y)
			{
				std::cout<<"Your closest guess was "<<i<<" .\n";
			}
			if(x<y)
			{
				std::cout<<"Your closest guess was "<<j<<" .\n";
			}
			std::cout<<"Would you like to play again? (y/n): ";
			std::cin>>next;
			if(next=='n')
			{
				std::cout<<"Goodbye!\n";
				break;
			}
			else if(next=='y')
			{
				k++;
				count=1;
			}
		}
		
	}while(k>=0);
	return(0);
}











	

