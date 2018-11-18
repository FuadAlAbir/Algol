#include <iostream>

using namespace std;

void insertionSort(int data[], int length)
{
    int i, j, key;
    for(i = 1; i < length; i++)
    {
        key = data[i];
        j = i - 1;
        while(j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

int main()
{
    int len;
    cin >> len;
    int data[len];
    
    for(int i = 0; i < len; i++) cin >> data[i];
    
    insertionSort(data, len);
    
    for(int i = 0; i < len; i++) cout << data[i] << " ";
    
    return 0;
}
