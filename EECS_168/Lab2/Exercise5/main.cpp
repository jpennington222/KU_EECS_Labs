/*
 * File Name: main.cpp
 * Author: Joseph Pennington
 * Assignment: EECS-169 Lab 2 Exercise 5
 * Description: This program is an interactive menu. The user will choose from a list of options. It will then print a reciept that includes tax.
 * Date: 9/14/2017
 */


#include <iostream>
int main(int argc, char** argv)

{
char choice;
char choicetop;
int count=0;

std::cout<<"Welcome to the Taco Stand \n\n";
std::cout<<"Place order: \n";
std::cout<<"============\n";
std::cout<<"(b/B) Beef Taco $3.5 \n"; 
std::cout<<"(s/S) Salad $5.0 \n";
std::cout<<"(w/W) Water $1.0 \n";
std::cout<<"Choice: ";
std::cin>>choice;
if(choice=='B' || choice=='b')
    {
    std::cout<<"Toppings: \n";
    std::cout<<"============\n";
    std::cout<<"(c/C) Cheese %1.5 \n";
    std::cout<<"(t/T) Tomatoes $0.75 \n";
    std::cout<<"(h/H) Hot Sauce $0.3 \n";
    std::cout<<"(n/N) None $0.0 \n";
    std::cout<<"Choice: ";
    std::cin>>choicetop;
    	   if(choicetop=='c' || choicetop=='C')
            {
            std::cout<<"Quantity: \n";
            std::cout<<"============\n";
            std::cout<<"How many?: ";
            std::cin>>count;
            std::cout<<"Receipt: \n";
            std::cout<<"============\n";
            std::cout<<"Sub total \n";
            	std::cout<<'\t'<<count<<" Beef Taco @ $3.5: $"<<(count*3.5)<<'\n';
            	std::cout<<'\t'<<count<<" Cheese @ $1.5: $"<<(count*1.5)<<'\n';
            std::cout<<"Tax \n";
            	std::cout<<'\t'<<"8% of $"<<((count*3.5)+(count*1.5))<<": $"<<((0.08*(count*3.5))+(0.08*(count*1.5)))<<'\n';
            std::cout<<"Total \n";
            	std::cout<<'\t'<<"$"<<((0.08*(count*3.5))+(0.08*(count*1.5))) + ((count*3.5)+(count*1.5))<<'\n';
            std::cout<<"Thank you!\n";
            }
            else if(choicetop=='t' || choicetop=='T')
            {
            std::cout<<"Quantity: \n";
            std::cout<<"============\n";
            std::cout<<"How many?: ";
            std::cin>>count;
            std::cout<<"Receipt: \n";
            std::cout<<"============\n";
            std::cout<<"Sub total \n";
            	std::cout<<'\t'<<count<<" Beef Taco @ $3.5: $"<<(count*3.5)<<'\n';
            	std::cout<<'\t'<<count<<" Tomatoes @ $0.75: $"<<(count*0.75)<<'\n';
            std::cout<<"Tax \n";
           	 std::cout<<'\t'<<"8% of $"<<((count*3.5)+(count*0.75))<<": "<<((0.08*(count*3.5))+(0.08*(count*0.75)))<<'\n';
            std::cout<<"Total \n";
            	std::cout<<'\t'<<"$"<<((0.08*(count*3.5))+(0.08*(count*1.5))) + ((count*3.5)+(count*1.5))<<'\n';
            std::cout<<"Thank you!\n";
            }
            else if(choicetop=='h' || choicetop=='H')
            {
            std::cout<<"Quantity: \n";
            std::cout<<"============\n";
            std::cout<<"How many?: ";
            std::cin>>count;
            std::cout<<"Receipt: \n";
            std::cout<<"============\n";
            std::cout<<"Sub total \n";
            	std::cout<<'\t'<<count<<" Beef Taco @ $3.5: $"<<(count*3.5)<<'\n';
           	std::cout<<'\t'<<count<<" Hot Sauce @ $0.3: $"<<(count*0.3)<<'\n';
            std::cout<<"Tax \n";
            	std::cout<<'\t'<<"8% of $"<<((count*3.5)+(count*0.3))<<": "<<((0.08*(count*3.5))+(0.08*(count*0.3)))<<'\n';
            std::cout<<"Total \n";
            	std::cout<<'\t'<<"$"<<((0.08*(count*3.5))+(0.08*(count*0.3))) + ((count*3.5)+(count*0.3))<<'\n';
            std::cout<<"Thank you!\n";
            }
            else if(choicetop=='n' || choicetop=='N')
            {
            std::cout<<"Quantity: \n";
            std::cout<<"============\n";
            std::cout<<"How many?: ";
            std::cin>>count;
            std::cout<<"Receipt: \n";
            std::cout<<"============\n";
            std::cout<<"Sub total \n";
            	std::cout<<'\t'<<count<<" Beef Taco @ $3.5: $"<<(count*3.5)<<'\n';
            std::cout<<"Tax \n";
            	std::cout<<'\t'<<"8% of $"<<(count*3.5)<<": "<<((0.08*(count*3.5)))<<'\n';
            std::cout<<"Total \n";
            	std::cout<<'\t'<<"$"<<((0.08*(count*3.5))) + (count*3.5)<<'\n';
            std::cout<<"Thank you!\n";
            }
	    else
	    {
	    std::cout<<"Invalid Entry!\n";
	    }
        }
    if(choice=='s' || choice=='S')
    {
    std::cout<<"Quantity: \n";
    std::cout<<"============\n";
    std::cout<<"How many?: ";
    std::cin>>count;
    std::cout<<"Receipt: \n";
    std::cout<<"============\n";
    std::cout<<"Sub total \n";
    	std::cout<<'\t'<<count<<" Salad @ $5.0: $"<<(count*5.0)<<'\n';
    std::cout<<"Tax \n";
    	std::cout<<'\t'<<"8% of $"<<(count*5.0)<<": "<<((0.08*(count*5.0)))<<'\n';
    std::cout<<"Total \n";
    	std::cout<<'\t'<<"$"<<((0.08*(count*5.0))) + (count*5.0)<<'\n';
    std::cout<<"Thank you!\n";
    }
    else if(choice=='w' || choice=='W')
    {
    std::cout<<"Quantity: \n";
    std::cout<<"============\n";
    std::cout<<"How many?: ";
    std::cin>>count;
    std::cout<<"Receipt: \n";
    std::cout<<"============\n";
    std::cout<<"Sub total \n";
    	std::cout<<'\t'<<count<<" Water @ $1.0: $"<<(count*1.0)<<'\n';
    std::cout<<"Tax \n";
    	std::cout<<'\t'<<"8% of $"<<(count*1.0)<<": "<<((0.08*(count*1.0)))<<'\n';
    std::cout<<"Total \n";
    	std::cout<<'\t'<<"$"<<((0.08*(count*1.0))) + (count*1.0)<<'\n';
    std::cout<<"Thank you!\n";
    }
    else
    {
    std::cout<<"Invalid Entry!\n";
    }
return (0);
}

