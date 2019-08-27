#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>

using namespace std;

class object
{
    public:
        int weight;
        int profit;
        bool isTaken;
};

int BruteForce(object objects[], int Size, int knapsackCap)
{
    bool flag = true;
    int bruteforceWeight = 0;
    int bruteforceProfit = 0;

    while(flag)
    {
        flag = false;
        int tempMax = 0, tempIndex = -1;
        for(int i = 0; i < Size; i++)
        {
            if(!objects[i].isTaken && objects[i].weight > tempMax)
            {
                tempMax = objects[i].weight;
                tempIndex = i;
                flag = true;
            }
        }

        if(objects[tempIndex].weight <= knapsackCap)
        {
                cout << "Weight: " << objects[tempIndex].weight << " Profit: " << objects[tempIndex].profit << endl;
                bruteforceWeight += objects[tempIndex].weight;
                bruteforceProfit += objects[tempIndex].profit;
                knapsackCap -= objects[tempIndex].weight;
        }
        objects[tempIndex].isTaken = true;
    }
    return bruteforceWeight;
}

int main()
{

    clock_t clock_time;         // clock_time stores clock_time in ms
    time_t random_seed;         // a variable of type time_t is declared, which holds seconds on clock
    time(&random_seed);         // get variable from system clock and store it in t
    srand(random_seed);         // pass random_seed as seed of rand()

    int min = 1;                // set min of random range
    int max = 5;                // set max of random range
    int knapsackCap = 0;
    int totalW = 0;

    vector <object> V;
    


    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    object obj[n];
    for(int i = 0; i < n; i++)
    {
        obj[i].weight = min + rand() % (( max + 1 ) - min);
        obj[i].profit = min + rand() % (( max + 1 ) - min);
    }

    for(int i = 0; i < n; i++)
    {
        totalW += obj[i].weight;
        cout << "Object: " << i << "\tWeight: " << obj[i].weight << "\tProfit: " << obj[i].profit << " " << endl;
    }
    knapsackCap = totalW * 0.7;
    cout << "\nObjects total weight: " << totalW << endl
         << "Knapsack Capasity: " << knapsackCap << endl << endl;

    // BRUTE FORCE
    cout << "\nTaken Weight: " << BruteForce(obj, n, knapsackCap) << endl;
}