#include <iostream>

using namespace std;

int main()
{
    int graph[5][2] = {{0, 2}, {1, 2}, {2, 3}, {2, 4}, {3, 4}};
    int adjMat[5][5] = {0};
    int row = -1;
    int col = -1;
    
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cout << graph[i][j] << " ";
            if(j == 0) row = graph[i][j];
            else col = graph[i][j];
        }
        adjMat[row][col] = 1;
        adjMat[col][row] = 1;
        cout << endl;
    }
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}