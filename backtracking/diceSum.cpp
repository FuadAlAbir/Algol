#include <iostream>
#include <vector>

using namespace std;

void diceSumHelper(int dice, vector <int>& chosen, int sumSoFar, int diceSum)
{
    if(dice == 0)
    {
        for(int i = 0; i < chosen.size(); i++)
        {
            cout << chosen[i] << " ";
        }
        cout << endl;
    }
    else
    {
        // dice left to add
        // handle one die
        // for each value dice can have
        for(int i = 1; i <= 6; i++)
        {
            // too big && too small
            if(sumSoFar + i + 1*(dice - 1) <= diceSum && sumSoFar + i + 6*(dice - 1) >= diceSum)
            {
                // choose
                chosen.push_back(i);
                // explore
                diceSumHelper(dice - 1, chosen, sumSoFar + i, diceSum);
                // unchoose
                chosen.pop_back();
            }
        }
    }
}

void diceSum(int dice, int diceSum)
{
    vector <int> chosen;
    diceSumHelper(dice, chosen, 0, diceSum);
}

int main()
{
    diceSum(2, 7);
}
