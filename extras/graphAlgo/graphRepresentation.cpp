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

int node;                      // # of nodes of the graph
int edge;                      // # of egdes of the graph
int row = -1;
int col = -1;


/*-------------------------------------------------
    U S E R   D E F I N E D   F U N C T I O N S
---------------------------------------------------
Function:   void addEdge(vector <int> adjList[], int u, int v);
Reason:     adding the edges to adjacency list
*/
void addEdge(vector <int> adjList[], int u, int v);
void adjacencyList(vector <int> adjList[], int node, int edge, int graph[][2]);
void adjacencyMatrix(int ** adjMat, int node, int edge, int graph[][2]);
int main()
{

    int start;                     // variable start is the starting node of BFS

    cout << "# of node(s): ";
    cin >> node;
    cout << "# of edge(s): ";
    cin >> edge;

    int graph[edge][2];             // graph Matrix with #egde rows and two columns
    int adjMat[node][node];         // adjMat Matrix with #node rows and #node columns
    vector <int> adjList[node];

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

    //----------------------------------------------------
    
    //----------------------------------------------------

    adjacencyMatrix(adjMat, node, edge, graph);
    adjacencyList(adjList, node, edge, graph);

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


void adjacencyMatrix(int ** adjMat, int node, int edge, int graph[][2])
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
void adjacencyList(vector <int> adjList[], int node, int edge, int graph[][2])
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

