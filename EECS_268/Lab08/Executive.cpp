/*
 * @Author: Joseph Pennington
 * @File Name: Executive.cpp
 * @Assignment: EECS 268 Lab 08
 * @Date: 11/13/2018
 * @Brief: This is the Executive cpp file
 */

#include "Executive.h"
using namespace std;

Executive::Executive(string order, string file)
{
  m_order = order;
  m_file = file;
  mystack = new Stack<BinaryNodeTree<string>*>();
  ifstream inFile;
  inFile.open(m_file);
  if(m_order == "postfix")
  {
    while(!inFile.eof())
    {
      string read = "";
      inFile>>read;
      if(read=="") break;
      if((read=="*") || (read=="/") || (read=="-") || (read=="+") || (read=="="))
      {
        try
        {
          BinaryNodeTree<string>* temp1= mystack->peek();
          mystack->pop();
          BinaryNodeTree<string>* temp2= mystack->peek();
          mystack->pop();
          BinaryNodeTree<string>* temptree= new BinaryNodeTree<string>(read,temp2,temp1);
          mystack->push(temptree);
          delete temp1;
          delete temp2;
        }

        catch(PrecondViolatedExcep err)
        {
          cout<<"Not enough operands \n";
        }
      }

      else
      {
        BinaryNodeTree<string>* temptree= new BinaryNodeTree<string>(read);
        mystack->push(temptree);
      }
    }

    inFile.close();
    try
    {
      mytree = mystack -> peek();
      mystack -> pop();
    }

    catch(PrecondViolatedExcep)
    {
      cout<<"Nothing in stack\n";
    }
  }

  else if(order == "prefix")
  {
    mytree = BuildTree(inFile);
    inFile.close();
  }
}

void Executive::run()
{
  cout<<"PreOrder Traverse\n";
  printTreePreorder(mytree);
  cout<<'\n';
  cout<<"InOrder Traverse\n";
  printTreeInorder(mytree);
  cout<<'\n';
  cout<<"PostOrder Traverse\n";
  printTreePostorder(mytree);
  cout<<'\n';
}

void Executive::printTreePreorder(BinaryNodeTree<string>* bt)
{
  bt -> preorderTraverse(visit);
  cout<<'\n';
}

void Executive::printTreeInorder(BinaryNodeTree<string>* bt)
{
  bt -> inorderTraverse(visit);
  cout<<'\n';
}

void Executive::printTreePostorder(BinaryNodeTree<string>* bt)
{
  bt -> postorderTraverse(visit);
  cout<<'\n';
}

void Executive::visit(string& str)
{
  cout<<str<<" ";
}

BinaryNodeTree<string>* Executive::BuildTree(ifstream& inFile)
{
  if(inFile.eof() == 0)
  {
    string read = "";

    inFile>>read;

    if((read=="*") || (read=="/") || (read=="-") || (read=="+") || (read=="="))
    {
      BinaryNodeTree<string>* temptree2= new BinaryNodeTree<string>(read,BuildTree(inFile),BuildTree(inFile));
      return(temptree2);
    }

    else
    {
      BinaryNodeTree<string>* temptree= new BinaryNodeTree<string>(read);
      return(temptree);
    }
  }
}

Executive::~Executive()
{
  delete mytree;
  delete mystack;
}
