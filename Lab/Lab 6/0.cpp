#include <bits/stdc++.h>
using namespace std;

int a = 10000;


typedef pair <int, int> p;

class Graph
{
    int node;
    list< pair<int, int> > *adjMat;
public:
    Graph(int node)
    {
        this -> node = node;
        adjMat = new list<p> [node];
    }
    void addEdge(int u, int v, int weight)
    {
        adjMat[u].push_back(make_pair(v, w));
        adjMat[v].push_back(make_pair(u, w));
    }
    void primMinST()
    {
        priority_queue<p, vector <p>, greater<p> > pq;
        int src = 0;
        vector<int> key(node, a);
        vector<int> parent(node, -1);
        vector<bool> inMST(node, false);

        pq.push(make_pair(0, src));
    }
}

int main()
{
}