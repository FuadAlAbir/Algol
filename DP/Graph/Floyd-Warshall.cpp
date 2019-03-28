#include <iostream>

#define INF 999

using namespace std;

/*
    A[node][node] = {   {0, 3, INF, 7},
                        {8, 0, 2, INF},
                        {5, INF, 0, 1},
                        {2, INF, INF, 0}    };
                        
S A M P L E   I N P U T
4
0 3 999 7
8 0 2 999
5 999 0 1
2 999 999 0

S A M P L E   O U T P U T
0 3 5 6
5 0 2 3
3 6 0 1
2 5 7 0
*/

int main()
{
    int node;

    cin >> node;
    int A[node][node];

    // USER-INPUT
    for(int i = 0; i < node; i++)
    {
        for(int j = 0; j < node; j++)
        {
            cin >> A[i][j];
        }
    }
    
    // FLOYD-WARSHALL Algo
    for(int k = 1; k <= node; k++)
    {
        for(int i = 0; i < node; i++)
        {
            for(int j = 0; j < node; j++)
            {
                A[i][j] = min( A[i][j], A[i][k - 1] + A[k - 1][j] );
            }
        }
        
        // PRINTING EACH MATRIX for K = 1 to K = node
        /*
        cout << "K = " << k << endl;
        for(int i = 0; i < node; i++)
        {
            for(int j = 0; j < node; j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        */
    }
    
    // PRINT RESULT
    for(int i = 0; i < node; i++)
    {
        for(int j = 0; j < node; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
