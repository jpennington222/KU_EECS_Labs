/*
 * @Author: Joseph Pennington
 * @File Name: Graph.cpp
 * @Assignment: EECS 560 Lab 10
 * @Brief: Implementation file for the Graph class
 */

#include "Graph.h"
using namespace std;

Graph::Graph(int** array, int size)
{
   currentEdges = 0;
   m_edges = new Edge[(size*size+1)/2];
   for(int i = 0; i < size; i++)
   {
     for(int j = i; j < size; j++)
     {
       if(i != j && array[i][j] != -1)
       {
         m_edges[currentEdges] = Edge(i,j,array[i][j]);
         currentEdges++;
       }
     }
   }
   m_size = size;
}
Graph::~Graph()
{
  delete[] m_edges;
}

void Graph::Prim(string m_names[])
{
    Edge* uncountedEdges = new Edge[currentEdges];
    for(int i = 0; i < currentEdges; i++)
    {
        uncountedEdges[i] = m_edges[i];
    }

    int edgesLeft = currentEdges;
    Edge* edgeArray = new Edge[currentEdges];
    int edgeCount = 0;
    bool* vertexArray = new bool[m_size];
    vertexArray[0] = true;

    for(int i =1; i< m_size; i++)
    {
        vertexArray[i] = false;
    }

    int verticesAdded = 1;
    minHeap<Edge> minQ;

    for(int i = 0; i < edgesLeft; i++)
    {
        if(vertexArray[uncountedEdges[i].m_start] != vertexArray[uncountedEdges[i].m_end])
        {
            minQ.insert(uncountedEdges[i]);
            minQ.heapify();
            if(i < edgesLeft-1)
            {
                uncountedEdges[i] = uncountedEdges[edgesLeft-1];
                i=i-1;
            }
            edgesLeft=edgesLeft-1;
        }
    }
    while(!minQ.isEmpty() && verticesAdded != m_size)
    {
        Edge edgeToAdd = minQ.findMin();
        minQ.deleteMin();
        minQ.heapify();
        if(vertexArray[edgeToAdd.m_start] != vertexArray[edgeToAdd.m_end])
        {
          vertexArray[edgeToAdd.m_start] = true;
          vertexArray[edgeToAdd.m_end] = true;
          verticesAdded++;

          edgeArray[edgeCount] = edgeToAdd;
          edgeCount++;
        }

        for(int i = 0; i < edgesLeft; i++)
        {
            if(vertexArray[uncountedEdges[i].m_start] != vertexArray[uncountedEdges[i].m_end])
            {
                minQ.insert(uncountedEdges[i]);
                minQ.heapify();
                if(i < edgesLeft-1) {
                    uncountedEdges[i] = uncountedEdges[edgesLeft-1];
                    i=i-1;
                }
                edgesLeft=edgesLeft-1;
            }
        }
    }
    if(edgeCount == m_size - 1)
    {
        int sum = 0;
        for(int i = 0; i < edgeCount; i++)
        {
            //cout << edgeArray[i] << " ";
            string start = to_string(edgeArray[i].m_start);
            string end = to_string(edgeArray[i].m_end);
            string cost = to_string(edgeArray[i].m_cost);

            if(start == "0")
            {
              cout << "(" << m_names[0] <<", ";
            }
            if(start == "1")
            {
              cout << "(" << m_names[1] <<", ";
            }
            if(start == "2")
            {
              cout << "(" << m_names[2] <<", ";
            }
            if(start == "3")
            {
              cout << "(" << m_names[3] <<", ";
            }
            if(start == "4")
            {
              cout << "(" << m_names[4] <<", ";
            }
            if(start == "5")
            {
              cout << "(" << m_names[5] <<", ";
            }
            if(start == "6")
            {
              cout << "(" << m_names[6] <<", ";
            }
            if(start == "7")
            {
              cout << "(" << m_names[7] <<", ";
            }
            if(start == "8")
            {
              cout << "(" << m_names[8] <<", ";
            }
            if(start == "9")
            {
              cout << "(" << m_names[9] <<", ";
            }
            if(start == "10")
            {
              cout << "(" << m_names[10] <<", ";
            }

            if(end == "0")
            {
              cout << m_names[0] <<")";
            }
            if(end == "1")
            {
              cout << m_names[1] <<")";
            }
            if(end == "2")
            {
              cout << m_names[2] <<")";
            }
            if(end == "3")
            {
              cout << m_names[3] <<")";
            }
            if(end == "4")
            {
              cout << m_names[4] <<")";
            }
            if(end == "5")
            {
              cout << m_names[5] <<")";
            }
            if(end == "6")
            {
              cout << m_names[6] <<")";
            }
            if(end == "7")
            {
              cout << m_names[7] <<")";
            }
            if(end == "8")
            {
              cout << m_names[8] <<")";
            }
            if(end == "9")
            {
              cout << m_names[9] <<")";
            }
            if(end == "10")
            {
              cout << m_names[10] <<")";
            }

            cout << "{" << cost << "}" << " ";
            sum = sum+edgeArray[i];
        }
        cout << '\n';
        cout << "Total length: " << sum << " miles\n";
        cout << "Total cost (length*250,000): $" << sum*250000 << endl;
    }
    else {
        cout << "There is no solution using Prims method\n";
    }
    delete[] vertexArray;
    delete[] uncountedEdges;
    delete[] edgeArray;
}

void Graph::Kruskal(string m_names[])
{
    Vertex** vertices = new Vertex*[m_size];
    for(int i = 0; i < m_size; i++)
    {
        vertices[i] = new Vertex(i);
    }

    minHeap<Edge> minEdges;
    for(int i = 0; i < currentEdges; i++)
    {
      minEdges.insert(m_edges[i]);
    }

    minEdges.heapify();
    int index = 0;
    Edge* mst = new Edge[currentEdges];
    Edge* temp = new Edge[currentEdges];

    while(index < m_size-1 && !minEdges.isEmpty())
    {
        mst[index] = minEdges.findMin();
        index++;
        minEdges.deleteMin();
        for(int i =0; i<m_size; i++)
        {
            vertices[i]->m_traversed = false;
        }

        vertices[mst[index-1].m_start]->DFS(temp);
        if(vertices[mst[index-1].m_end]->m_traversed == false)
        {
            vertices[mst[index-1].m_start]->connectTo(vertices[mst[index-1].m_end]);
            vertices[mst[index-1].m_end]->connectTo(vertices[mst[index-1].m_start]);
        }
        else
        {
            index=index-1;
        }
    }
    if(index == m_size-1)
    {
        int sum = 0;
        for(int i = 0; i < index; i++)
        {
          //cout << mst[i] << '\n';
          string start = to_string(mst[i].m_start);
          string end = to_string(mst[i].m_end);
          string cost = to_string(mst[i].m_cost);

          if(start == "0")
          {
            cout << "(" << m_names[0] <<", ";
          }
          if(start == "1")
          {
            cout << "(" << m_names[1] <<", ";
          }
          if(start == "2")
          {
            cout << "(" << m_names[2] <<", ";
          }
          if(start == "3")
          {
            cout << "(" << m_names[3] <<", ";
          }
          if(start == "4")
          {
            cout << "(" << m_names[4] <<", ";
          }
          if(start == "5")
          {
            cout << "(" << m_names[5] <<", ";
          }
          if(start == "6")
          {
            cout << "(" << m_names[6] <<", ";
          }
          if(start == "7")
          {
            cout << "(" << m_names[7] <<", ";
          }
          if(start == "8")
          {
            cout << "(" << m_names[8] <<", ";
          }
          if(start == "9")
          {
            cout << "(" << m_names[9] <<", ";
          }
          if(start == "10")
          {
            cout << "(" << m_names[10] <<", ";
          }

          if(end == "0")
          {
            cout << m_names[0] <<")";
          }
          if(end == "1")
          {
            cout << m_names[1] <<")";
          }
          if(end == "2")
          {
            cout << m_names[2] <<")";
          }
          if(end == "3")
          {
            cout << m_names[3] <<")";
          }
          if(end == "4")
          {
            cout << m_names[4] <<")";
          }
          if(end == "5")
          {
            cout << m_names[5] <<")";
          }
          if(end == "6")
          {
            cout << m_names[6] <<")";
          }
          if(end == "7")
          {
            cout << m_names[7] <<")";
          }
          if(end == "8")
          {
            cout << m_names[8] <<")";
          }
          if(end == "9")
          {
            cout << m_names[9] <<")";
          }
          if(end == "10")
          {
            cout << m_names[10] <<")";
          }

          cout << "{" << cost << "}" << " ";

          sum += mst[i];
        }
        cout << endl;
        cout << "Total length: " << sum << " miles\n";
        cout << "Total cost (length*250,000): $" << sum*250000 << endl;
    }
    else
    {
        cout << "There is no solution using Kruskals method\n";
    }
    delete[] mst;
    delete[] temp;
    for(int i = 0; i < m_size; i++) {
        delete vertices[i];
    }
    delete[] vertices;
}
void Graph::DFS(string m_names[])
{
    Vertex** vertices = new Vertex*[m_size];
    for(int i = 0; i < m_size; i++)
    {
        vertices[i] = new Vertex(i);
    }
    Edge* crossEdgeArray = new Edge[currentEdges];
    int numberOfCrossEdges = currentEdges;
    int index = 0;
    minHeap<Edge> minEdges;

    for(int i = 0; i < currentEdges; i++)
    {
      minEdges.insert(m_edges[i]);
    }
    minEdges.heapify();

    while(!minEdges.isEmpty())
    {
        Edge minCostEdge = minEdges.findMin();
        vertices[minCostEdge.m_start]->connectTo(vertices[minCostEdge.m_end]);
        crossEdgeArray[index] = minCostEdge;
        index++;
        minEdges.deleteMin();
    }

    Edge* treeEdges = new Edge[currentEdges];
    cout << "Tree Edges: ";
    int numberOfTreeEdges = vertices[0]->DFS(treeEdges);

    for (int i = 0; i < numberOfTreeEdges-1; i++)
    {
       for (int j = 0; j < numberOfTreeEdges-i-1; j++)
       {
           if (treeEdges[j].m_start > treeEdges[j+1].m_start || (treeEdges[j].m_start == treeEdges[j+1].m_start && treeEdges[j].m_end > treeEdges[j+1].m_end))
           {
            Edge temp = treeEdges[j];
            treeEdges[j] = treeEdges[j+1];
            treeEdges[j+1] = temp;
           }
        }
   }

    for(int i = 0; i < numberOfTreeEdges; i++)
    {
        //cout << "(" << treeEdges[i].m_start << ", " << treeEdges[i].m_end << ") ";
        cout << "(";
        if(treeEdges[i].m_start == 0)
        {
          cout << m_names[0] << ", ";
        }
        if(treeEdges[i].m_start == 1)
        {
          cout << m_names[1] << ", ";
        }
        if(treeEdges[i].m_start == 2)
        {
          cout << m_names[2] << ", ";
        }
        if(treeEdges[i].m_start == 3)
        {
          cout << m_names[3] << ", ";
        }
        if(treeEdges[i].m_start == 4)
        {
          cout << m_names[4] << ", ";
        }
        if(treeEdges[i].m_start == 5)
        {
          cout << m_names[5] << ", ";
        }
        if(treeEdges[i].m_start == 6)
        {
          cout << m_names[6] << ", ";
        }
        if(treeEdges[i].m_start == 7)
        {
          cout << m_names[7] << ", ";
        }
        if(treeEdges[i].m_start == 8)
        {
          cout << m_names[8] << ", ";
        }
        if(treeEdges[i].m_start == 9)
        {
          cout << m_names[9] << ", ";
        }
        if(treeEdges[i].m_start == 10)
        {
          cout << m_names[10] << ", ";
        }

        if(treeEdges[i].m_end == 0)
        {
          cout << m_names[0] << ") ";
        }
        if(treeEdges[i].m_end == 0)
        {
          cout << m_names[0] << ") ";
        }
        if(treeEdges[i].m_end == 1)
        {
          cout << m_names[1] << ") ";
        }
        if(treeEdges[i].m_end == 2)
        {
          cout << m_names[2] << ") ";
        }
        if(treeEdges[i].m_end == 3)
        {
          cout << m_names[3] << ") ";
        }
        if(treeEdges[i].m_end == 4)
        {
          cout << m_names[4] << ") ";
        }
        if(treeEdges[i].m_end == 5)
        {
          cout << m_names[5] << ") ";
        }
        if(treeEdges[i].m_end == 6)
        {
          cout << m_names[6] << ") ";
        }
        if(treeEdges[i].m_end == 7)
        {
          cout << m_names[7] << ") ";
        }
        if(treeEdges[i].m_end == 8)
        {
          cout << m_names[8] << ") ";
        }
        if(treeEdges[i].m_end == 9)
        {
          cout << m_names[9] << ") ";
        }
        if(treeEdges[i].m_end == 10)
        {
          cout << m_names[10] << ") ";
        }
    }

    for(int i = 0; i < numberOfTreeEdges; i++)
    {
        for(int j = 0; i < numberOfCrossEdges; j++)
        {
            if(crossEdgeArray[j] == treeEdges[i])
            {
                numberOfCrossEdges=numberOfCrossEdges-1;
                crossEdgeArray[j] = crossEdgeArray[numberOfCrossEdges];
                break;
            }
         }
    }
    cout << endl;
    cout << "Back Edges: ";

   for (int i = 0; i < numberOfCrossEdges-1; i++)
   {
       for (int j = 0; j < numberOfCrossEdges-i-1; j++)
       {
           if (crossEdgeArray[j].m_start > crossEdgeArray[j+1].m_start || (crossEdgeArray[j].m_start == crossEdgeArray[j+1].m_start && crossEdgeArray[j].m_end > crossEdgeArray[j+1].m_end))
           {
            Edge temp = crossEdgeArray[j];
            crossEdgeArray[j] = crossEdgeArray[j+1];
            crossEdgeArray[j+1] = temp;
           }
        }
   }

    for(int i = 0; i < numberOfCrossEdges; i++)
    {
        //cout << "(" << crossEdgeArray[i].m_start << ", " << crossEdgeArray[i].m_end << ") ";
        cout << "(";
        if(crossEdgeArray[i].m_start == 0)
        {
          cout << m_names[0] << ", ";
        }
        if(crossEdgeArray[i].m_start == 1)
        {
          cout << m_names[1] << ", ";
        }
        if(crossEdgeArray[i].m_start == 2)
        {
          cout << m_names[2] << ", ";
        }
        if(crossEdgeArray[i].m_start == 3)
        {
          cout << m_names[3] << ", ";
        }
        if(crossEdgeArray[i].m_start == 4)
        {
          cout << m_names[4] << ", ";
        }
        if(crossEdgeArray[i].m_start == 5)
        {
          cout << m_names[5] << ", ";
        }
        if(crossEdgeArray[i].m_start == 6)
        {
          cout << m_names[6] << ", ";
        }
        if(crossEdgeArray[i].m_start == 7)
        {
          cout << m_names[7] << ", ";
        }
        if(crossEdgeArray[i].m_start == 8)
        {
          cout << m_names[8] << ", ";
        }
        if(crossEdgeArray[i].m_start == 9)
        {
          cout << m_names[9] << ", ";
        }
        if(crossEdgeArray[i].m_start == 10)
        {
          cout << m_names[10] << ", ";
        }

        if(crossEdgeArray[i].m_end == 0)
        {
          cout << m_names[0] << ") ";
        }
        if(crossEdgeArray[i].m_end == 0)
        {
          cout << m_names[0] << ") ";
        }
        if(crossEdgeArray[i].m_end == 1)
        {
          cout << m_names[1] << ") ";
        }
        if(crossEdgeArray[i].m_end == 2)
        {
          cout << m_names[2] << ") ";
        }
        if(crossEdgeArray[i].m_end == 3)
        {
          cout << m_names[3] << ") ";
        }
        if(crossEdgeArray[i].m_end == 4)
        {
          cout << m_names[4] << ") ";
        }
        if(crossEdgeArray[i].m_end == 5)
        {
          cout << m_names[5] << ") ";
        }
        if(crossEdgeArray[i].m_end == 6)
        {
          cout << m_names[6] << ") ";
        }
        if(crossEdgeArray[i].m_end == 7)
        {
          cout << m_names[7] << ") ";
        }
        if(crossEdgeArray[i].m_end == 8)
        {
          cout << m_names[8] << ") ";
        }
        if(crossEdgeArray[i].m_end == 9)
        {
          cout << m_names[9] << ") ";
        }
        if(crossEdgeArray[i].m_end == 10)
        {
          cout << m_names[10] << ") ";
        }
    }

    for(int i = 0; i < m_size; i++)
    {
        delete vertices[i];
    }
    delete[] vertices;
    delete[] crossEdgeArray;
    delete[] treeEdges;
}

void Graph::BFS(string m_names[])
{
    Vertex** vertices = new Vertex*[m_size];
    for(int i = 0; i < m_size; i++)
    {
        vertices[i] = new Vertex(i);
    }
    minHeap<Edge> minEdges;
    for(int i = 0; i < currentEdges; i++)
    {
      minEdges.insert(m_edges[i]);
    }
    minEdges.heapify();
    Edge* crossEdges = new Edge[currentEdges];
    int numberOfCrossEdges = currentEdges;
    int index = 0;
    while(!minEdges.isEmpty())
    {
        Edge minCostEdge = minEdges.findMin();
        vertices[minCostEdge.m_start]->connectTo(vertices[minCostEdge.m_end]);
        crossEdges[index] = minCostEdge;
        index++;
        minEdges.deleteMin();
    }
    Edge* treeEdges = new Edge[currentEdges];
    cout << "Tree Edges: ";
    int numberOfTreeEdges = vertices[0]->BFS(treeEdges);

    for (int i = 0; i < numberOfTreeEdges-1; i++)
    {
       for (int j = 0; j < numberOfTreeEdges-i-1; j++)
       {
           if (treeEdges[j].m_start > treeEdges[j+1].m_start ||
              (treeEdges[j].m_start == treeEdges[j+1].m_start && treeEdges[j].m_end > treeEdges[j+1].m_end))
              {
            Edge temp = treeEdges[j];
            treeEdges[j] = treeEdges[j+1];
            treeEdges[j+1] = temp;
           }
        }
   }
    for(int i = 0; i < numberOfTreeEdges; i++)
    {
        //cout << "(" << treeEdges[i].m_start << ", " << treeEdges[i].m_end << ") ";
        cout << "(";
        if(treeEdges[i].m_start == 0)
        {
          cout << m_names[0] << ", ";
        }
        if(treeEdges[i].m_start == 1)
        {
          cout << m_names[1] << ", ";
        }
        if(treeEdges[i].m_start == 2)
        {
          cout << m_names[2] << ", ";
        }
        if(treeEdges[i].m_start == 3)
        {
          cout << m_names[3] << ", ";
        }
        if(treeEdges[i].m_start == 4)
        {
          cout << m_names[4] << ", ";
        }
        if(treeEdges[i].m_start == 5)
        {
          cout << m_names[5] << ", ";
        }
        if(treeEdges[i].m_start == 6)
        {
          cout << m_names[6] << ", ";
        }
        if(treeEdges[i].m_start == 7)
        {
          cout << m_names[7] << ", ";
        }
        if(treeEdges[i].m_start == 8)
        {
          cout << m_names[8] << ", ";
        }
        if(treeEdges[i].m_start == 9)
        {
          cout << m_names[9] << ", ";
        }
        if(treeEdges[i].m_start == 10)
        {
          cout << m_names[10] << ", ";
        }

        if(treeEdges[i].m_end == 0)
        {
          cout << m_names[0] << ") ";
        }
        if(treeEdges[i].m_end == 0)
        {
          cout << m_names[0] << ") ";
        }
        if(treeEdges[i].m_end == 1)
        {
          cout << m_names[1] << ") ";
        }
        if(treeEdges[i].m_end == 2)
        {
          cout << m_names[2] << ") ";
        }
        if(treeEdges[i].m_end == 3)
        {
          cout << m_names[3] << ") ";
        }
        if(treeEdges[i].m_end == 4)
        {
          cout << m_names[4] << ") ";
        }
        if(treeEdges[i].m_end == 5)
        {
          cout << m_names[5] << ") ";
        }
        if(treeEdges[i].m_end == 6)
        {
          cout << m_names[6] << ") ";
        }
        if(treeEdges[i].m_end == 7)
        {
          cout << m_names[7] << ") ";
        }
        if(treeEdges[i].m_end == 8)
        {
          cout << m_names[8] << ") ";
        }
        if(treeEdges[i].m_end == 9)
        {
          cout << m_names[9] << ") ";
        }
        if(treeEdges[i].m_end == 10)
        {
          cout << m_names[10] << ") ";
        }
    }
    for(int i = 0; i < numberOfTreeEdges; i++)
    {
        for(int j = 0; i < numberOfCrossEdges; j++)
        {
            if(crossEdges[j] == treeEdges[i])
            {
                numberOfCrossEdges=numberOfCrossEdges-1;
                crossEdges[j] = crossEdges[numberOfCrossEdges];
                break;
            }
         }
    }
    cout << '\n';
    cout << "Cross Edges: ";

   for (int i = 0; i < numberOfCrossEdges-1; i++)
   {
       for (int j = 0; j < numberOfCrossEdges-i-1; j++)
       {
           if (crossEdges[j].m_start > crossEdges[j+1].m_start || (crossEdges[j].m_start == crossEdges[j+1].m_start && crossEdges[j].m_end > crossEdges[j+1].m_end))
           {
            Edge temp = crossEdges[j];
            crossEdges[j] = crossEdges[j+1];
            crossEdges[j+1] = temp;
           }
        }
   }
    for(int i = 0; i < numberOfCrossEdges; i++)
    {
        //cout << "(" << crossEdges[i].m_start << ", " << crossEdges[i].m_end << ") ";
        cout << "(";
        if(crossEdges[i].m_start == 0)
        {
          cout << m_names[0] << ", ";
        }
        if(crossEdges[i].m_start == 1)
        {
          cout << m_names[1] << ", ";
        }
        if(crossEdges[i].m_start == 2)
        {
          cout << m_names[2] << ", ";
        }
        if(crossEdges[i].m_start == 3)
        {
          cout << m_names[3] << ", ";
        }
        if(crossEdges[i].m_start == 4)
        {
          cout << m_names[4] << ", ";
        }
        if(crossEdges[i].m_start == 5)
        {
          cout << m_names[5] << ", ";
        }
        if(crossEdges[i].m_start == 6)
        {
          cout << m_names[6] << ", ";
        }
        if(crossEdges[i].m_start == 7)
        {
          cout << m_names[7] << ", ";
        }
        if(crossEdges[i].m_start == 8)
        {
          cout << m_names[8] << ", ";
        }
        if(crossEdges[i].m_start == 9)
        {
          cout << m_names[9] << ", ";
        }
        if(crossEdges[i].m_start == 10)
        {
          cout << m_names[10] << ", ";
        }

        if(crossEdges[i].m_end == 0)
        {
          cout << m_names[0] << ") ";
        }
        if(crossEdges[i].m_end == 0)
        {
          cout << m_names[0] << ") ";
        }
        if(crossEdges[i].m_end == 1)
        {
          cout << m_names[1] << ") ";
        }
        if(crossEdges[i].m_end == 2)
        {
          cout << m_names[2] << ") ";
        }
        if(crossEdges[i].m_end == 3)
        {
          cout << m_names[3] << ") ";
        }
        if(crossEdges[i].m_end == 4)
        {
          cout << m_names[4] << ") ";
        }
        if(crossEdges[i].m_end == 5)
        {
          cout << m_names[5] << ") ";
        }
        if(crossEdges[i].m_end == 6)
        {
          cout << m_names[6] << ") ";
        }
        if(crossEdges[i].m_end == 7)
        {
          cout << m_names[7] << ") ";
        }
        if(crossEdges[i].m_end == 8)
        {
          cout << m_names[8] << ") ";
        }
        if(crossEdges[i].m_end == 9)
        {
          cout << m_names[9] << ") ";
        }
        if(crossEdges[i].m_end == 10)
        {
          cout << m_names[10] << ") ";
        }
    }
    for(int i = 0; i < m_size; i++)
    {
        delete vertices[i];
    }
    delete[] vertices;
    delete[] crossEdges;
    delete[] treeEdges;
}
