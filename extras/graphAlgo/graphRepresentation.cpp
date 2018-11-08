/*-----------------------------
    I N T R O D U C T I O N
-------------------------------
Author:         Fuad Al Abir
Dated:          November 7, 2018
Name:           graphRepresentation.cpp
Objective:      This program creates Adjacency Matrix and Adjacency list from a directed or undirected graph. Pairwise connected nodes are the inputs.
Algorithms:     Brute force
Problem Source: https://www.geeksforgeeks.org/graph-and-its-representations/
Instructor:     None
*/
/*-------------------------------------------
    S A M P L E   I N P U T - O U T P U T
---------------------------------------------
INPUT:
# of node(s): 15
# of edge(s): 14
Enter the connected nodes, pairwise: 5 3 3 4 4 0 4 1 1 0 1 2 3 2 5 9 2 8 6 7 11 12 11 14 12 14 13 10

OUTPUT:
Nodes with Edges: {{5, 3}, {3, 4}, {4, 0}, {4, 1}, {1, 0}, {1, 2}, {3, 2}, {5, 9}, {2, 8}, {6, 7}, {11, 12}, {11, 14}, {12, 14}, {13, 10}}

Adjacency Matrix:
0 1 0 0 1 0 0 0 0 0 0 0 0 0 0
1 0 1 0 1 0 0 0 0 0 0 0 0 0 0
0 1 0 1 0 0 0 0 1 0 0 0 0 0 0
0 0 1 0 1 1 0 0 0 0 0 0 0 0 0
1 1 0 1 0 0 0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0 0 0 0 1 0 1
0 0 0 0 0 0 0 0 0 0 0 1 0 0 1
0 0 0 0 0 0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 1 1 0 0

Adjacency list:
Node: 0 -> 4 -> 1
Node: 1 -> 4 -> 0 -> 2
Node: 2 -> 1 -> 3 -> 8
Node: 3 -> 5 -> 4 -> 2
Node: 4 -> 3 -> 0 -> 1
Node: 5 -> 3 -> 9
Node: 6 -> 7
Node: 7 -> 6
Node: 8 -> 2
Node: 9 -> 5
Node: 10 -> 13
Node: 11 -> 12 -> 14
Node: 12 -> 11 -> 14
Node: 13 -> 10
Node: 14 -> 11 -> 12
*/
/*-----------------------------
    H E A D E R   F I L E S
-------------------------------
Header: iostream
Reason: Input/Output stream - cin, cout
Header: vector
Reason: Using the data structure, vector to create Adjacency List
*/
#include <iostream>
#include <vector>

using namespace std;

/*-------------------------------------------------
    U S E R   D E F I N E D   F U N C T I O N S
---------------------------------------------------
Function:   void addEdge(vector <int> adjList[], int u, int v);
Reason:     adding the edges to adjacency list
Parameters: vector <int> adjList[]: vector array reference in which all the edges will be added
            int u, int v: {u, v} nodes that are connected by an edge

Function:   void adjacencyMatrix(int ** adjMat, int graph[][2], int node, int edge);
Reason:     Creating and Printing Adjacency Matrix
Parameter:  vector ** adjMat - double pointer reference from which Adjacency Matrix is printed, created from graph[][2]
            int graph[][2] - a primitive 2D array where pairwise nodes were taken
            int node - # of nodes
            int edge - # of edge

Function:   void adjacencyList(vector <int> adjList[], int node, int edge, int graph[][2]);
Reason:     Creating And Printing Adjacency List
Parameter:  vector <int> adjList[]: vector array reference from which Adjacency List is printed, created from graph[][2]
            int graph[][2]:         a primitive 2D array where pairwise nodes were taken
            int node:               # of nodes
            int edge:               # of edge
*/
void addEdge(vector <int> adjList[], int u, int v);
void adjacencyMatrix(int ** adjMat, int graph[][2], int node, int edge);
void adjacencyList(vector <int> adjList[], int graph[][2], int node, int edge);

/*-----------------------------------
    G L O B A L   V A R I B L E S
-----------------------------------*/
int row = -1;                   // variable row is used in creating Adjacency Matrix
int col = -1;                   // variable col is used in creating Adjacency Column

/*-------------------------------
    M A I N   F U N C T I O N
-------------------------------*/
int main()
{
    int node;                       // # of nodes of the graph
    int edge;                       // # of egdes of the graph
    int start;                      // variable start is the starting node of BFS, DFS

    cout << "# of node(s): ";
    cin >> node;
    cout << "# of edge(s): ";
    cin >> edge;

    int graph[edge][2];             // graph Matrix with #egde rows and two columns

    int *adjMat[node];              // adjMat Matrix with #node rows and #node columns*/
    int i = node;
    while(i--)
    {
        adjMat[i] = new int[node];
    }

    vector <int> adjList[node];     // Array of vectors to create Ajdacency List

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

    adjacencyMatrix(adjMat, graph, node, edge);
    adjacencyList(adjList, graph, node, edge);

    return 0;
}

/*---------------------------------------------------------
    A D D   E G D E   T O   A D J A C E N C Y   L I S T
---------------------------------------------------------*/
void addEdge(vector <int> adjList[], int u, int v)
{
    adjList[u].push_back(v);
    /*** For Directed graph, one have just to eleminate or comment-out the following single line ***/
    adjList[v].push_back(u);
}

// printing Adjacency Matrix

void adjacencyMatrix(int ** adjMat, int graph[][2], int node, int edge)
{
    cout << "\nNodes with Edges: ";
    for(int i = 0; i < edge; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            // printing the connected nodes pairwise
            if(i == 0 && j == 0)
            {
                cout << "{{" << graph[i][j] << ", ";
            }
            else if(j == 0)
            {
                cout << "{" << graph[i][j] << ", ";
            }
            else if(i != edge - 1)
            {
                cout << graph[i][j] << "}, ";
            }
            else
            {
                cout << graph[i][j] << "}}" << endl;
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
    cout << "\nAdjacency Matrix:" << endl;
    for(int i = 0; i < node; i++)
    {
        for(int j = 0; j < node; j++)
        {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
}


// printing Adjacency List
void adjacencyList(vector <int> adjList[], int graph[][2], int node, int edge)
{
    // Adding egdes in adjacency list
    for(int i = 0; i < edge; i++)
    {
        addEdge(adjList, graph[i][0], graph[i][1]);
    }
    cout << "\nAdjacency list:" << endl;
    for (int i = 0; i < node; i++) 
    { 
        cout << "Node: " << i;
        for (int j = 0; j < adjList[i].size(); j++)
        {
           cout << " -> " << adjList[i][j];
        }
        cout << endl;
    }
}

