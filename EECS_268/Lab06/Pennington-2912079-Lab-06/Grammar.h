/*
 * @Author: Joseph Pennington
 * @File Name: main.cpp
 * @Assignment: EECS 268 Lab 06
 * @Date: 10/16/2018
 * @Brief: This program is the header file for the Grammar class.
 */

#ifndef GRAMMAR_H
#define GRAMMAR_H
#include <string>
#include <vector>
#include <map>
using namespace std;

class Grammar
{
public:

    /*
		* @pre: none
		* @post: The input file strings are stored and other functions are called
		* @param questionF: Question file
    * @param answerF: Answer file
		* @return: none
		*/

  Grammar(string questionF, string answerF);

    /*
  	* @pre: Grammar object made
  	* @post: Grammars are infiled and stored to the map
  	* @param File: file name
  	* @return: Map with infiled contents
  	*/

  map<string, vector<vector<string>>> read_grammar(string File);

    /*
		* @pre: Grammar object made
		* @post: Stores sentences to be made
		* @param g: Map of infiled contents
		* @return: vector of sentence
		*/

  vector<string> gen_sentence(const map<string, vector<vector<string>>>& g);

    /*
		* @pre: Grammar object made
		* @post: Recursively makes sentences
		* @param g: Map of infiled contents
    * @param word: Start word
    * @param ret: Return vector
		* @return: Vector od sentences
		*/

  void gen_aux(const map<string, vector<vector<string>>>& g, const string& word, vector<string>& ret);

    /*
		* @pre: Grammar object made
		* @post: String is put into vector split on space
		* @param str: String that is the input
		* @return: Vector that contains the string
		*/

  vector<string> split(const string& str);

    /*
  	* @pre: Grammar object made
  	* @post: Creates question string from question vector
  	* @return: Question to be printed
  	*/

  string getQuestion();

    /*
    * @pre: Grammar object made
    * @post: Creates answer string from question vector
    * @return: Answer to be printed
    */

  string getAnswer();

    /*
    * @pre: Grammar object made
    * @post: Deletes object
    * @return: none
    */

  ~Grammar();

private:
  string QuestionFile;
  string AnswerFile;
  string start;
  vector<string> QuestionV;
  vector<string> AnswerV;
};
#endif
