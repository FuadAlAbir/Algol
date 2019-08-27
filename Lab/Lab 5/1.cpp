#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void addEdge(vector <int> adjList[], int u, int v)
{
    adjList[u].push_back(v);
}


void adjacencyList(vector <int> adjList[], int graph[][2], int node, int edge)
{
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

void dfs(vector <int> adjList[], int start, int node)
{
    int visited[node];
    int edgeID[node];
    for(int i = 0; i < node; i++)
    {
        visited[i] = 0;
        edgeID[i] = 0;
    }
    
    cout << "\nDepth First Search: ";
    stack <int> s;
    s.push(start);
    while(!s.empty())
    {
        int u = s.top();
        if(visited[u] == 0)
        {
            cout << u << " ";
        }

        // Checking if a node can be traversed to the root
        if(u != start)
        {
            for (int i = 0; i < node; i++) 
            { 
                for (int j = 0; j < adjList[i].size(); j++)
                {
                    cout << adjList[i][j] << " ";
                    if (adjList[i][j] == start)
                    {
                        // Printing "YES" if the root node
                        // can be traversed from
                        // a particular node
                        cout << "\n\nYES\n";
                        return;
                    }
                }
            }    
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

int main()
{
    int node;
    int edge;
    int start;

    cout << "Number of node(s): ";
    cin >> node;
    cout << "Number of edge(s): ";
    cin >> edge;

    int graph[edge][2];
    int *adjMat[node];
    int i = node;
    while(i--)
    {
        adjMat[i] = new int[node];
    }
    vector <int> adjList[node];

    for(int i = 0; i < edge; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            graph[i][j] = 0;
        }
    }
    
    for(int i = 0; i < node; i++)
    {
        for(int j = 0; j < node; j++)
        {
            adjMat[i][j] = 0;
        }
    }

    cout << "Enter the connected nodes, pairwise: ";
    for(int c = 0; c < edge; c++)
    {
        for(int r = 0; r < 2; r++)
        {
            cin >> graph[c][r];
        }
    }

    adjacencyList(adjList, graph, node, edge);
    cout << "\nGraph Traversal starting Node: ";
    cin >> start;
    dfs(adjList, start, node);

    return 0;
}