/*-----------------------------
    I N T R O D U C T I O N
-------------------------------
Author:     Fuad Al Abir
Date:       January 20, 2019
Name:       kruskal.cpp
Objective:  Finding the maximum profit for 0/1 Knapsack problem using Dynamic Programming approach.
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int max2(int a, int b)
{
    if(a >= b) return a;
    else return b;
}

int main()
{
    time_t random_seed;
    time(&random_seed);
    srand(random_seed);
    
    int n_object;
    cout << "Number of Objects: ";

    cin >> n_object;
    int weight[n_object + 1];
    int profit[n_object + 1];
    cout << endl;
    cout << "Weight\tProfit" << endl;
    for(int i = 1; i <= n_object; i++)
    {
        weight[i] = 1 + rand() % 5;
        profit[i] = 1 + rand() % 10;
        cout << weight[i] << "\t" << profit[i] << endl;
    }
    int knapsack_weight;
    cout << endl;
    cout << "Knapsack Weight: ";
    cin >> knapsack_weight;

    int knapsackDP[n_object + 1][knapsack_weight + 1];

    for(int i = 0; i <= n_object; i++)
    {
        for(int w = 0; w <= knapsack_weight; w++)
        {
            knapsackDP[i][w] = 0;
        }
    }

    for(int i = 1; i <= n_object; i++)
    {
        for(int w = 1; w <= knapsack_weight; w++)
        {
            if(weight[i] > w) knapsackDP[i][w] = knapsackDP[i - 1][w];
            else knapsackDP[i][w] = max2( profit[i] + knapsackDP[i-1][w-weight[i]], knapsackDP[i-1][w]);
        }
    }

    for(int i = 0; i <= n_object; i++)
    {
        for(int w = 0; w <= knapsack_weight; w++)
        {
            cout << knapsackDP[i][w] << "  ";
        }
        cout << endl;
    }

    cout << "\nProfit: " << knapsackDP[n_object][knapsack_weight] << endl;
}