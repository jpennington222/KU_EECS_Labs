/*                                                                              
 * File Name: WordGuessingGame.cpp                                            
 * Author: Joseph Pennington                                                    
 * Assignment: EECS 169 Lab 4 Exercise 2                                        
 * Description: This program will have the user guess a word and the program will say how close the guess was                              
 * Date: 10/02/2017                                                              
 */


#include <iostream>
#include <string>

int main()
{
int j = 0;
int match = 0;
char next = '\0';


	std::string word ("valentine");
	std::string guess ("\0");
	std::cout<<"Welcome to the word guessing game.\n";
	while(j>=0)
	{
		std::cout<<"Guess a word: ";
		std::cin>>guess;
		if(guess.length() < word.length())
		{
			std::cout<<"The word is longer\n";
			std::cout<<"Incorrect. ";
			j++;
		}
		else if(guess.length() > word.length())
		{
			std::cout<<"The word is shorter\n";
			std::cout<<"Incorrect. ";
			j++;
		}
		else if(guess.length() == word.length())
		{
			for(unsigned int i=0; i<word.length(); i++)
			{
				if(word[i]==guess[i])
				{
					match=match+1;
				}
			}
			if(match>0 && match<=8)
			{
				std::cout<<"You have "<<match<<" letters correct\n";
				std::cout<<"Incorrect. ";
				match=0;
			}
			else if(match==9)
			{
				std::cout<<"You win!\n";
				std::cout<<"Would you like to play again? (y/n): ";
				std::cin>>next;
				if(next=='n')
				{
					std::cout<<"Goodbye\n";
					break;
				}
				else if(next=='y')
				{
					j++;
				}
			}
		}
	}
	return(0);
}
