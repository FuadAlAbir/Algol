#include <iostream>
#include <string>
using namespace std;

void printBinary(int digit, string prefix = "")
{
    if(digit == 0)
        cout << prefix << endl;
    else
    {
        printBinary(digit - 1, prefix + "0");
        printBinary(digit - 1, prefix + "1");
    }
}

int main()
{
    printBinary(3);
}
