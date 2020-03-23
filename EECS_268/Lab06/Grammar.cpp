/*
 * @Author: Joseph Pennington
 * @File Name: main.cpp
 * @Assignment: EECS 268 Lab 06
 * @Date: 10/16/2018
 * @Brief: This program is the cpp file for the Grammar class.
 */

 #include "Grammar.h"
 #include <iostream>
 #include <fstream>
 #include <sstream>
 #include <istream>
 #include <iterator>
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 using namespace std;

Grammar::Grammar(string questionF, string answerF)
{
  QuestionFile = questionF;
  AnswerFile = answerF;
  start = "QUESTION";
  QuestionV = gen_sentence(read_grammar(QuestionFile));
  start = "ANSWER";
  AnswerV = gen_sentence(read_grammar(AnswerFile));
}

map<string, vector<vector<string>>> Grammar::read_grammar(string File)
 {
   string line;
   map<string, vector<vector<string>>> ret;

   ifstream inFile;
   inFile.open(File);
   while(getline(inFile, line, '#'))
   {
     vector<string> entry = split(line);
     if(!entry.empty())
     {
       ret[entry[0]].push_back(vector<string>(entry.begin()+1, entry.end()));
     }
   }
   inFile.close();
   return(ret);
 }

vector<string> Grammar::gen_sentence(const map<string, vector<vector<string>>>& g)
{
  vector<string> ret;
  gen_aux(g, start, ret);
  return(ret);
}


void Grammar::gen_aux(const map<string, vector<vector<string>>>& g, const string& word, vector<string>& ret)
{
  bool NonT = false;
  int random = 0;
  srand(time(NULL));

  for(map<string, vector<vector<string>>>::const_iterator it=g.begin(); it!=g.end(); ++it)
  {
    if((it -> first) == word)
    {
      NonT = true;
    }
  }

  if(NonT == false)
  {
    ret.push_back(word);
  }

  else
  {
    map<string, vector<vector<string>>>::const_iterator it = g.find(word);
    const vector<vector<string>>& c = it -> second;
    random = rand() % c.size();
    const vector<string>& r = c[random];
    for(vector<string>::const_iterator i = r.begin(); i != r.end(); ++i)
    {
      gen_aux(g, *i, ret);
    }
  }
}

vector<string> Grammar::split(const string& str)
{
    string s = str;
    stringstream ss(s);
    istream_iterator<string> begin(ss);
    istream_iterator<string> end;
    vector<string> vstrings(begin, end);
    return(vstrings);
}

string Grammar::getQuestion()
{
  string ret = "";
  for(auto const& s : QuestionV) {ret += s + ' ';}
  return(ret);
}

string Grammar::getAnswer()
{
  string ret = "";
  for(auto const& s : AnswerV) {ret += s + ' ';}
  return(ret);
}

Grammar::~Grammar()
{

}
