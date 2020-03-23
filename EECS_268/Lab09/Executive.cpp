/*
 * @Author: Joseph Pennington
 * @File Name: Executive.cpp
 * @Assignment: EECS 268 Lab 09
 * @Date: 12/04/2018
 * @Brief: This is the Executive cpp file
 */

#include "Executive.h"
Executive* Executive::theExec=nullptr;
using namespace std;

Executive::Executive(string file)
{
  m_file = file;
  theExec=this;
}

Executive::Executive()
{
  theExec = this;
}

void Executive::run()
{
    theExec=this;
    string command = "";
    int tempID;
    string tempName = "";
    int tempEstTime;
    string present = "";
    m_time = 0;
    int nodes = 0;

    fstream inFile;
    inFile.open(m_file);
    if(inFile.is_open() == false)
    {
      cout<<"The file could not be opened\n";
      exit(0);
    }

    tree = new BinarySearchTree<int, Task>();
    while(!inFile.eof())
    {
      command = "";
      tempID = 0;
      tempName = "";
      tempEstTime = 0;
      present = "";

      inFile>>command;
      if(command == "add")
      {
        cout<<"======= add =======\n";
        inFile>>tempID;
        inFile>>tempName;
        inFile>>tempEstTime;

        if(tree -> contains(tempID) == true)
        {
          cout<<tempID<<" already exists in the BST\n";
        }

        else
        {
          Task tempTask(tempID, tempName, tempEstTime, m_time, -1);
          tree -> add(tempTask);
          cout<<tempID<<" has been added\n";
          nodes = nodes +1;
        }
        cout<<"===================\n\n";
      }

      if(command == "numberNodes")
      {
        if(tree -> getHeight() == 0)
        {
          nodes = 0;
        }

        cout<<"=== numberNodes ===\n";
        cout<<"Number of Nodes: "<<nodes<<'\n';
        cout<<"===================\n\n";
      }

      if(command == "height")
      {
        cout<<"===== height =====\n";
        cout<<"Height: "<<tree -> getHeight()<<'\n';
        cout<<"===================\n\n";
      }

      if(command == "taskPresent")
      {
        cout<<"=== taskPresent ===\n";
        inFile>>tempID;
        if(tree -> contains(tempID) == false)
        {
          cout<<tempID<<" not found\n";
        }

        else
        {
          Task tempPresent = tree -> getEntry(tempID);
          cout<<"Task ID: "<<tempID<<'\n';
          cout<<"Task Name: "<<tempPresent.gettaskName()<<'\n';
          cout<<"Estimated Time To Complete: "<<tempPresent.getestimatedTimeToComplete()<<'\n';
          cout<<"Time Added To BST: "<<tempPresent.gettimeAddedToBST()<<'\n';
          cout<<"Time Started: "<<tempPresent.gettimeStarted()<<'\n';
        }
        cout<<"===================\n\n";
      }

      if(command == "start")
      {
        inFile>>tempID;
        start(tempID);
      }

      if(command == "started")
      {
        cout<<"===== started =====\n";
        inFile>>tempID;
        if(tree -> contains(tempID) == false)
        {
          cout<<tempID<<" not found\n";
        }

        else
        {
          Task tempStarted = tree -> getEntry(tempID);
          if(tempStarted.gettimeStarted() == -1)
          {
            cout<<tempID<<" has not started\n";
          }

          else
          {
            cout<<tempID<<" has started\n";
          }
        }
        cout<<"===================\n\n";
      }

      if(command == "finish")
      {

        inFile>>tempID;
        finish(tempID);

      }

      if(command == "flush")
      {

        nodes = 0;
        cout<<"====== flush ======\n";
        flush();

      }

      if(command == "")
      {
        break;
      }
      m_time = m_time + 1;
    }

    inFile.close();
}

void Executive::start(int tempID)
{
  cout<<"====== start ======\n";
  int TS = 0;
  int TID = 0;
  string TN = "";
  int ETTC = 0;
  int TATB = 0;

  if(tree -> contains(tempID) == false)
  {
    cout<<tempID<<" not found\n";
  }

  else
  {
    Task tempStart = tree -> getEntry(tempID);
    if(tempStart.gettimeStarted() == -1)
    {
      TS = m_time;
      TID = tempStart.gettaskID();
      TN = tempStart.gettaskName();
      ETTC = tempStart.getestimatedTimeToComplete();
      TATB = tempStart.gettimeAddedToBST();
      tree -> remove(tempID);
      Task tempTask(TID, TN, ETTC, TATB, TS);
      tree -> add(tempTask);

      cout<<tempID<<" has started\n";
      cout<<"Task ID: "<<tempID<<'\n';
      cout<<"Task Name: "<<TN<<'\n';
      cout<<"Estimated Time To Complete: "<<ETTC<<'\n';
      cout<<"Time Added To BST: "<<TATB<<'\n';
      cout<<"Time Started: "<<TS<<'\n';

    }

    else
    {
      cout<<tempID<<" has already been started\n";
    }
  }
  cout<<"===================\n\n";
}

void Executive::finish(int tempID)
{
    cout<<"===== finish =====\n";
  if(tree -> contains(tempID) == false)
  {
    cout<<tempID<<" not found\n";
  }

  else
  {
    Task tempFinish = tree -> getEntry(tempID);
    if(tempFinish.gettimeStarted() == -1)
    {
      cout<<tempID<<" has not started\n";
    }

    else
    {
      cout<<"Task ID: "<<tempID<<'\n';
      cout<<"Task Name: "<<tempFinish.gettaskName()<<'\n';
      cout<<"Estimated Time To Complete: "<<tempFinish.getestimatedTimeToComplete()<<'\n';
      cout<<"Time Added To BST: "<<tempFinish.gettimeAddedToBST()<<'\n';
      cout<<"Time Started: "<<tempFinish.gettimeStarted()<<'\n';
      cout<<"Time Finished: "<<m_time<<'\n';
      tree -> remove(tempID);
      nodes = nodes -1;
    }
  }
  cout<<"===================\n\n";
}

void Executive::flush()
{
  tree -> postorderTraverse(visit);
}

void Executive::visit(Task& ID)
{
  int tempID = ID.gettaskID();
  theExec -> start(tempID);
  theExec -> finish(tempID);
}

Executive::~Executive()
{
  delete tree;
}
