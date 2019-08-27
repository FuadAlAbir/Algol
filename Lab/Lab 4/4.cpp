#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef pair <int, int> P;
vector <object> V;

bool compare(P x, P y)
{
    return x.second * y.first > x.first * y.second;
}

void knapstack_greedy()
{
    int n, w;
    int maximum = 15;
    int minimum = 1;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int weight = minimum + rand() % (( maximum + 1 ) - minimum);
        int profit = minimum + rand() % (( maximum + 1 ) - minimum);
        w += weight;
        cout << "Weight: " << weight << " Profit: " << profit << endl;
        V.push_back(P(weight, profit));
    }
    sort(V.begin(), V.end(), compare);
    w *= 0.7;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int z = min(w, V[i].first);
        w -= z;
        ans += (z + V[i].second);
    }
    cout << "MaxCost: " << ans;
}

int main()
{
    knapstack_greedy();
}