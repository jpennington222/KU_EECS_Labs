/*
 * @Author: Joseph Pennington
 * @File Name: main.cpp
 * @Assignment: EECS 560 Lab 09
 * @Brief: This program is the main file for the lab. It saves the input file name and passes of the work to the classes.
 */

 #include <iostream>
 #include <string>
 #include <fstream>
 #include "Executive.h"
 using namespace std;

 int main(int argc, char* argv[])
 {
   if(argc == 2)
   {
     Executive exec(argv[1]);
     exec.run();
   }
   else if(argc != 2)
   {
     cout << "Error opening file\n";
   }
   return (0);
 }
