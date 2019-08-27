#include <iostream>
#include <algorithm>

using namespace std;

/*
1. Create Edge class
2. Input graph
*** KRUSKAL'S ALGO STARTS HERE ***
3. Sort edges with respect to weight (compare is for this)
4. Create output array of type Edge, size n - 1
5. Create parent array and initialize them with themselves
6. count, i
7. Check if we can add currentEdge in MST or not (Check by finding the parent of the edges)
8. if parents are not equal, add edge to MST and update parent
*/

class Edge
{
    public:
        int source;
        int dest;
        int weight;
};

bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

int findParent(int v, int *parent)
{
    if(parent[v] == v)
    {
        return v;
    }
    return findParent(parent[v], parent);
}

void printMST(Edge *output, int n)
{
    cout << "\nMinimum Spanning Tree using Kruskals Algorithm\n";
    for(int i = 0; i < n - 1; i++)
    {
        if(output[i].source < output[i].dest)
        {
            cout << output[i].source << " ";
            cout << output[i].dest << " ";
            cout << output[i].weight;
            cout << endl;
        }
        else
        {
            cout << output[i].dest << " ";
            cout << output[i].source << " ";
            cout << output[i].weight;
            cout << endl;
        }
    }
}

void kruskals(Edge *input, int n, int E)
{
    sort(input, input + E, compare);
    
    Edge *output = new Edge[n - 1];
    
    int *parent = new int[n];
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    
    
    int count = 0;
    int i = 0;
    while(count != n - 1)
    {
        Edge currentEdge = input[i];
        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.dest, parent);
        
        if(sourceParent != destParent)
        {
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
    }
    
    printMST(output, n);

}

int main()
{
    int n, E;
    cout << "Enter the number of Nodes and Edges: ";
    cin >> n >> E;
    // Creating input array of size E, type Edge
    Edge *input = new Edge[E];
    
    for(int i = 0; i < E; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }
    
    kruskals(input, n, E);
    

}





