#include<bits/stdc++.h>

using namespace std;

class Edge
{
public:
    int u;
    int v;
    int weight;
};

class Vertex
{
public:
    int data;
    int Rank;
    Vertex* parent;
};

Vertex* getParent(Vertex* v)
{
    if(v->data == (v->parent)->data)
        return v;
    else
        getParent(v->parent);
}


void Swap(Edge &a,Edge &b)
{
    Edge temp;
    temp.u = b.u;
    temp.v = b.v;
    temp.weight = b.weight;
    b.u = a.u;
    b.v = a.v;
    b.weight = a.weight;
    a.u = temp.u;
    a.v = temp.v;
    a.weight = temp.weight;
}


int main()
{
    ofstream TheGraph("Graph.txt");
    srand(time(0));

    int Number_of_Vertex;
    cout<<"\t\t\tNo. OF VERTEX___";
    cin>>Number_of_Vertex;
    cout<<"\n\t\t\t___Vertexes ARE___\n\t\t\t";
    for(int i=0;i<Number_of_Vertex;i++)
        cout<<i<<"  ";
    cout<<" \n\n";
    vector<Edge> Edges;
    Vertex Vertexs[Number_of_Vertex];

    cout<<"\nThe Graph is : \n";
    for(int i=0;i<Number_of_Vertex;i++)
    {
        Vertexs[i].data = i;
        Vertexs[i].Rank = 1;
        Vertexs[i].parent = &Vertexs[i];
        for(int j=i+1;j<Number_of_Vertex;j++)
        {
            int temp = rand() % 100;
            if((rand()%100)%2 == 0)
            {
                Edge E;
                E.u = i;
                E.v = j;
                E.weight = temp;
                Edges.push_back(E);
                cout<<i<<" - "<<j<<" = "<<temp<<endl;
                TheGraph<<i<<" - "<<j<<" = "<<temp<<endl;
            }
        }
    }
    for(int i=0;i<Number_of_Vertex;i++)
    {
        for(int j=0;j<Number_of_Vertex-i;j++)
        {
            if(Edges[j].weight>Edges[j+1].weight)
            {
                Swap(Edges[j],Edges[j+1]);
            }
        }
    }
    vector<Edge> Result;

    for(int i=0;i<Number_of_Vertex;i++)
    {
        Vertex* u = getParent(&Vertexs[Edges[i].u]);
        Vertex* v = getParent(&Vertexs[Edges[i].v]);
        if(u->data != v->data)
        {
            Result.push_back(Edges[i]);
            if(u->Rank>v->Rank)
            {
                v->parent = u;
                u->Rank+=v->Rank;
            }
            else
            {
                u->parent = v;
                v->Rank+=u->Rank;
            }
        }
    }
    cout<<"\n\nThe minimum spanning tree is :\n";
    for(int i=0;i<Result.size();i++)
    {
        cout<<Result[i].u<<" - "<<Result[i].v<<"  =  "<<Result[i].weight<<endl;
    }

    getchar();
    getchar();

    return 0;
}
