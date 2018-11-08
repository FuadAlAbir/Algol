/*-----------------------------
    I N T R O D U C T I O N
-------------------------------
Author:         Fuad Al Abir
Dated:          November 7, 2018
Name:           graphComponents.cpp
Objective:      
Algorithms:     
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
Graph Traversal starting Node: 5

OUTPUT:
Breadth First Search: 5 3 9 4 2 0 1 8
Breadth First Search: 6 7
Breadth First Search: 10 13
Breadth First Search: 11 12 14

Total Components: 4

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

using namespace std;

/*-------------------------------------------------
    U S E R   D E F I N E D   F U N C T I O N S
---------------------------------------------------
Function:   void addEdge(vector <int> adjList[], int u, int v);
Reason:     adding the edges to adjacency list
Parameters: vector <int> adjList[]: vector array reference in which all the edges will be added
            int u, int v: {u, v} nodes that are connected by an edge
Return:     void

Function:   vector <int> bfs(vector <int> adjList[], int start, int node);
Reason:     Breadth First Search Algorithm is implemented here
Parameters: vector <int> adjList[] - vector array reference from which BFS is processed
            int start - Starting node for BFS
            int node - # of nodes
Return:     vector <int> - <traversed nodes> <# of node traversed>

Function:   vector <int> dfs(vector <int> adjList[], int start, int node);
Reason:     Depth First Search Algorithm is implemented here
Parameters: vector <int> adjList[]: vector array reference from which DFS is processed
            int start - Starting node for DFS
            int node - # of nodes
Return:     vector <int> - <traversed nodes> <# of node traversed>

Function:   int component(vector <int> adjList[], int start, int node);
Reason:     To find the components
Parameters: vector <int> adjList[]: vector array reference from which DFS is processed
            int start - Starting node for BFS of DFS
            int node - # of nodes
Return:     int - # of components
*/
void addEdge(vector <int> adjList[], int u, int v);
vector <int> bfs(vector <int> adjList[], int start, int node);
vector <int> dfs(vector <int> adjList[], int start, int node);
int component(vector <int> adjList[], int start, int node);

/*-------------------------------
    M A I N   F U N C T I O N
-------------------------------*/
int main()
{
    int node;                      // # of nodes of the graph
    int edge;                      // # of egdes of the graph
    int start;                     // variable start is the starting node of BFS

    cout << "# of node(s): ";
    cin >> node;
    cout << "# of edge(s): ";
    cin >> edge;

    int graph[edge][2];             // graph Matrix with #egde rows and two columns
    vector <int> adjList[node];

    // Initializing all the rows and cols of graph Matrix to 0
    for(int i = 0; i < edge; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            graph[i][j] = 0;
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
    
    cout << "Graph Traversal starting Node: ";
    cin >> start;
    cout << endl;
    cout << "\nTotal Components: " << component(adjList, start, node) << endl;
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
vector <int> bfs(vector <int> adjList[], int start, int node)
{
    vector <int> returnVector;
    int counter = 0;                    // counts # of data searched
    int visited[node];
    for(int i = 0; i < node; i++)
    {
        visited[i] = 0;
    }

    queue <int> Q;
    Q.push(start);
    visited[start] = 1;

    cout << "Breadth First Search: ";
    while(!Q.empty())
    {
        int u = Q.front();
        returnVector.push_back(u);
        cout << u << " ";
        counter++;
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
    returnVector.push_back(counter);
    // returns vector: <traversed nodes> <# of node traversed>
    return returnVector;
}

/*-------------------------------------------
    D E A P T H   F I R S T   S E A R C H
-------------------------------------------*/
vector <int> dfs(vector <int> adjList[], int start, int node)
{
    vector <int> returnVector;
    int counter = 0;
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
            returnVector.push_back(u);
            cout << u << " ";
        }

        visited[u] = 1;
        counter++;
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
    returnVector.push_back(counter);
    // returns vector: <traversed nodes> <# of node traversed>
    return returnVector;
}

/*-----------------------------------------
    F I N D I N G   C O M P O N E N T S
-----------------------------------------*/
int component(vector <int> adjList[], int start, int node)
{
    vector <int> visited;
    vector <int> temp;
    int counterNode = 0;
    int counterBFS = 0;

    for(int j = 0; j < node; j++)
    {
        visited.push_back(0);
    }
    while(counterNode < node)
    {
        counterBFS++;
        temp = bfs(adjList, start, node);
        for(int j = 0; j < temp.size() - 1; j++)
        {
            counterNode++;
            visited[temp[j]] = 1;
        }

        for(int j = 0; j < visited.size(); j++)
        {
            if(visited[j] == 0)
            {   
                start = j;
                break;
            }
        }
    }
    return counterBFS;
}