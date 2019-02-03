#include <iostream>
#include <vector>

using namespace std;

void diceRollHelper(int dice, vector <int>& chosen)
{
    if(dice == 0)
    {
        // base case - no dice left to roll
        for(int i = 0; i < chosen.size(); i++)
            cout << chosen[i] << " ";
        cout << endl;
    }
    else
    {
        // dice left to roll
        // handle one die
        // for each value dice can have
        for(int i = 1; i <= 6; i++)
        {
            // choose
            chosen.push_back(i);
            // explore
            diceRollHelper(dice - 1, chosen);
            // unchoose
            chosen.pop_back();
        }
    }
}

void diceRoll(int dice)
{
    vector <int> chosen;
    diceRollHelper(dice, chosen);
}

int main()
{
    diceRoll(2);
}
