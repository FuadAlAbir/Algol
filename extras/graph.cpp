/*-----------------------------
    I N T R O D U C T I O N
-------------------------------
Author:         Fuad Al Abir
Dated:          November 7, 2018
Name:           graph.cpp
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
Header: queue
Reason: Using the data structure, queue in BFS
*/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include<bits/stdc++.h> 


using namespace std;

/*-------------------------------------------------
    U S E R   D E F I N E D   F U N C T I O N S
---------------------------------------------------
Function:   void addEdge(vector <int> adjList[], int u, int v);
Reason:     adding the edges to adjacency list
Function:   void bfs(vector <int> adjList[], int s, int node);
Reason:     for Beadth First Search
Function:   void dfs(vector <int> adjList[], int start, int node);
Reason:     for Depth First Search
*/
void addEdge(vector <int> adjList[], int u, int v);
void bfs(vector <int> adjList[], int s, int node);
void dfs(vector <int> adjList[], int start, int node);

int main()
{
    int node;                      // # of nodes of the graph
    int edge;                      // # of egdes of the graph
    int row;                       // variable row used in setting up adjoint matrix
    int col;                       // variable col used in setting up adjoint matrix
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

    // Adding egdes in adjacency list
    for(int i = 0; i < edge; i++)
    {
        addEdge(adjList, graph[i][0], graph[i][1]);
    }

    row = -1;
    col = -1;

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
    // printing Adjacency List
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
    cout << "\nGraph Traversal starting Node: ";
    cin >> start;
    bfs(adjList, start, node);
    dfs(adjList, start, node);
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

/*---------------------------------------------
    B R E A D T H   F I R S T   S E A R C H
---------------------------------------------*/
void bfs(vector <int> adjList[], int start, int node)
{
    int visited[node];
    for(int i = 0; i < node; i++)
    {
        visited[i] = 0;
    }

    queue <int> Q;
    Q.push(start);
    visited[start] = 1;

    cout << "\nBreadth First Search: ";
    while(!Q.empty())
    {
        int u = Q.front();
        cout << u << " ";
        Q.pop();

        for(int i = 0; i < adjList[u].size(); i++)
        {
            if(visited[adjList[u][i]] == 0)
            {
                int v = adjList[u][i];
                visited[v] = 1;
                Q.push(v);
            }
        }
    }
    cout << endl;
}

/*-------------------------------------------
    D E A P T H   F I R S T   S E A R C H
-------------------------------------------*/
void dfs(vector <int> adjList[], int start, int node)
{
    int visited[node];
    int edgeID[node];
    for(int i = 0; i < node; i++)
    {
        visited[i] = 0;
        edgeID[i] = 0;
    }
    cout << "Depth First Search: ";
    stack <int> s;
    s.push(start);
    while(!s.empty())
    {
        int u = s.top();
        if(visited[u] == 0)
        {
        cout << u << " ";
        }

        visited[u] = 1;
        s.pop();
        
        while(edgeID[u] < adjList[u].size())
        {
            int v = adjList[u][edgeID[u]];
            edgeID[u]++;
            if(visited[v] == 0)
            {
                s.push(u);
                s.push(v);
                break;
            }
        }
    }
    cout << endl;
}