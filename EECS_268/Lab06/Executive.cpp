/*
 * @Author: Joseph Pennington
 * @File Name: main.cpp
 * @Assignment: EECS 268 Lab 06
 * @Date: 10/16/2018
 * @Brief: This program is the cpp file for the Executive class.
 */

 #include "Executive.h"
 #include <fstream>
 #include <iostream>
 using namespace std;

 Executive::Executive(string questionF, string answerF)
 {
   QF = questionF;
   AF = answerF;

   string line;
   ifstream inFile;
   ifstream inFile2;
   inFile.open(QF);
   cout<<"\n=== Question Production Rules ===\n";
   while(getline(inFile, line, '#'))
   {
     cout<<line;
   }
   inFile.close();
   cout<<'\n';
   cout<<"=== Answer Production Rules ===\n";

   inFile2.open(AF);
   while(getline(inFile2, line, '#'))
   {
     cout<<line;
   }
   inFile2.close();
   cout<<'\n';
 }

void Executive::run()
{
  bool again = true;
  char stop = '\0';

  while(again == true)
  {
    cout<<"Enter command: ";
    cin>>stop;

    if(stop == 'A')
    {
      Grammar GQ(QF, AF);
      cout<<GQ.getQuestion()<<'\n';
      cout<<GQ.getAnswer()<<'\n';
    }

    else if(stop == 'Q')
    {
      again = false;
    }

    else
    {
      cout<<"Please Input A or Q\n";
    }
  }
  cout<<'\n';
}

Executive::~Executive()
{
  //delete GQ;
}
