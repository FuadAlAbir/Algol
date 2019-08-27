#include <iostream>
#include <stack>

using namespace std;

int n;
int chess_board[100][100];
int row[100];

int is_safe(int i,int j)
{
    int k, l;

    if(i == 0 && j == 0) return 1;

    for(k = 0; k < n; k++)
    {
        if((chess_board[i][k] == 1) || (chess_board[k][j] == 1))
            return 0;
    }

    for(k = 0; k < n; k++)
    {
        for(l = 0; l < n; l++)
        {
            if(((k + l) == ( i + j)) || (( k - l) == ( i - j)))
            {
                if(chess_board[k][l] == 1)
                    return 0;
            }
        }
    }
    return 1;
}

void clear_chess_board()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            chess_board[i][j] = 0;
        }
    }
}

void print_chess_board()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << chess_board[i][j] << " ";
        }
        cout << endl;
    }
}

int n_queen()
{
    if(n <= 3) return 1;
    else 
    {
        for(int a = 0; a < n; a++)
        {
            chess_board[0][a] = 1;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(is_safe(i, j) && chess_board[i][j] == 0) chess_board[i][j] = 1;
                    else
                    {
                        chess_board[0][a] = 0;
                        continue;
                    }
                }
            }
        }
    }
}

int main()
{
    stack <int> s;
    cout << "Enter the value of n: ";
    cin >> n;

    clear_chess_board();

    if(n_queen() == 1) clear_chess_board();


    print_chess_board();

}
