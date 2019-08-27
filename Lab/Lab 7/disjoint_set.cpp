#include <iostream>

using namespace std;

int *parent = new int[100];
int *rankParent = new int[100];

void initializeSet(int n)
{
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
        rankParent[i] = 0;
    }
}

int findParent(int v)
{
    if(parent[v] == v) return v;
    else return parent[v] = findParent(parent[v]);
}

void unionSet(int u, int v)
{
    int parent_u = findParent(u);
    int parent_v = findParent(v);

    if(parent_u == parent_v) return;

    if(rankParent[parent_u] < rankParent[parent_v]) parent[parent_u] = parent_v;
    else if(rankParent[parent_u] > rankParent[parent_v]) parent[parent_v] = parent_u;
    else
    {
        parent[parent_v] = parent_u;
        rankParent[parent_u]++;
    }
}

void printSet(int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "Node: " << i << " Parent: " << parent[i] << " Rank: " << rankParent[i] << endl;
    }
    cout << endl;
}

void number_of_set(int n)
{
    int set = 0;
    for(int i = 0; i < n; i++)
    {
        if(parent[i] == i) set++;
    }
    cout << "Number of Disjoint Set: " << set << endl;
}

int main()
{
    int n;
    cout << "Number of Nodes: ";
    cin >> n;

    initializeSet(n);
    unionSet(0, 1);
    unionSet(4, 2);
    unionSet(3, 1);
    unionSet(0, 3);
    unionSet(0, 4);

    printSet(n);

    number_of_set(n);
}