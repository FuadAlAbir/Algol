#include <iostream>
#include <string>

using namespace std;

void printDecimal(int digit, string prefix = "")
{
    if(digit == 0)
        cout << prefix << endl;
    else
        for(int i = 0; i <= 9; i++)
            printDecimal(digit - 1, prefix + to_string(i));
}

int main()
{
    printDecimal(3);
    
    return 0;
}
