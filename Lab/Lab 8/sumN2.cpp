/*-----------------------------
    I N T R O D U C T I O N
-------------------------------
Author:     Fuad Al Abir
Date:       January 21, 2019
Name:       SumofN.cpp
Objective:  Finding the elements of a set that can sum up to N using Dynamic Programming approach.
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    time_t random_seed;
    time(&random_seed);
    srand(random_seed);
    
    cout << "Number of elements: ";
    int element;
    cin >> element;

    int set[element];
    cout << endl;
    cout << "Set: { ";
    for(int i = 1; i <= element; i++)
    {
        set[i] = 1+rand()%5;
        if(i != element) cout << set[i] << ", ";
        else cout << set[i] << " }";
    }

    cout << endl << endl << "N: ";
    int n;
    cin >> n;

    int T[n + 1][element + 1];
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= element; j++)
        {
            T[i][j] = 0;
        }
    }

    for(int i = 1;i <= n; i++)
    {
        for(int j = 1; j <= element; j++)
        {
            if(i == set[j])
            {
                T[i][j] = 1;
            }
            else if(i < set[j]){
                T[i][j] = T[i][j-1];
            }
            else{
                if(T[i - set[j]][j - 1])
                    T[i][j] = 1;
                else
                    T[i][j] = 0;
            }
        }
    }
    
    cout << endl << "  | ";
    for(int i = 0; i <= element; i++) cout << i << " ";
    cout << endl << "--------------------";

    cout << endl;
    for(int i = 0; i <= n; i++)
    {
        cout << i << " | ";
        for(int j = 0; j <= element; j++)
        {
            cout << T[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

