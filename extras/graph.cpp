/*-----------------------------
    I N T R O D U C T I O N
-------------------------------
Author: Fuad Al Abir
Dated: November 7, 2018
Name: graph.cpp
Objective: This program creates Adjacency Matrix from a graph (Directed and un-directed). Pairwise connected nodes are the inputs.
Algorithms: Brute force
Problem Source: https://www.geeksforgeeks.org/graph-and-its-representations/
Instructor: None
*/
/*-----------------------------
    H E A D E R   F I L E S
-------------------------------
Header: iostream
Reason: Input/Output stream - cin, cout
*/

#include <iostream>

using namespace std;

int main()
{
    int node;                       // # of nodes of the graph
    int edge;                       // # of egdes of the graph
    cout << "# of node(s): ";
    cin >> node;
    cout << "# of edge(s): ";
    cin >> edge;
    int graph[edge][2];             // graph Matrix with #egde rows and two columns
    int adjMat[node][node];         // adjMat Matrix with #node rows and #node columns

    // Initializing all the rows and cols of graph Matrix to 0
    for(int i = 0; i < edge; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            graph[i][j] = 0;
        }
    }
    // Initializing all the rows and cols of adjMat Matrix to 0
    for(int i = 0; i < node; i++)
    {
        for(int j = 0; j < node; j++)
        {
            adjMat[i][j] = 0;
        }
    }
    
    // Scanning connected nodes of the graph pairwise
    cout << "Enter the connected nodes, pairwise: ";
    for(int c = 0; c < edge; c++)
    {
        for(int r = 0; r < 2; r++)
        {
            cin >> graph[c][r];
        }
    }

    int row = -1;
    int col = -1;

    cout << "\nNodes with Edges: ";
    
    for(int i = 0; i < edge; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            // printing the connected nodes pairwise
            if(j == 0)
            {
                cout << "{" << graph[i][j] << ", ";
            }
            else if(i != edge - 1)
            {
                cout << graph[i][j] << "}, ";
            }
            else
            {
                cout << graph[i][j] << "}" << endl;
            }
            // detecting the rows and cols that are connected
            if(j == 0) row = graph[i][j];
            else col = graph[i][j];
        }
        // setting up adjoint matrix by the connections
        adjMat[row][col] = 1;
        /*** For Directed graph, one have just to eleminate or comment-out the following single line ***/
        adjMat[col][row] = 1;
    }

    // printing Adjacency Matrix
    cout << "\nAdjacency Matrix:" << endl;
    for(int i = 0; i < node; i++)
    {
        for(int j = 0; j < node; j++)
        {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}