// ARRAY based representation of DYNAMIC LIST

#include <iostream>
#include <new>

using namespace std;

int size = 10;
int *ax = new (nothrow) int[size];      // dynamic memory allocation
                                        // starts with size 10
int count = 0;

void size_renew()
{
    size *= 2;
    int axx[size];
    for(int i = 0; i < count; i++)
    {
        axx[i] = ax[i];
    }
    
    delete []ax;                        // free main array memory
    ax = new (nothrow) int[size];       // new memory allocated

    for(int i = 0; i < count; i++)
    {
        ax[i] = axx[i];
    }
}

void insert(int n)                      // INSERT an item
{
    if(count >= size)
    {
        size_renew();
        ax[count] = n;
        count++;
    }
    else
    {
        ax[count] = n;
        count++;
    }
}

void insert(int n, int pos)             // INSERT an item with position
{
    if(pos < count)
    {
        int cur = count;
        while(cur >= pos)
        {
            ax[cur + 1] = ax[cur];
            cur--;
        }
        ax[pos] = n;
        count++;
    }
    else
    {
        ax[count] = n;
    }
}

void rm(int pos)                        // REMOVE an item
{
    if(pos = count)
    {
        ax[count] = 0;
        count--;
    }
    else if(pos < count)
    {
        int cur = pos;
        while(cur != count)
        {
            ax[cur] = ax[cur + 1];
            cur++;
        }
        ax[count] = 0;
        count--;
    }
}

void list_size()                        // SIZE of list
{
    cout << "Size: " << count << endl;
}

void print()                            // PRINT the list
{
    if(count > 0)
    {
        for(int i = 0; i < count; i++)
        {
            cout << ax[i] << " ";
        }
    }
}

int main()
{
    
    insert(5);
    insert(3);
    insert(5);
    insert(3);
    insert(5);
    insert(3);
    insert(2, 0);
    insert(2, 0);
    insert(4, 0);
    insert(5);
    insert(1);
    insert(5);
    insert(3);
    insert(5);
    insert(3);
    insert(5);
    insert(3);
    insert(2, 0);
    insert(2, 0);
    insert(4, 0);
    insert(5);
    insert(1);

    print();
    
    return 0;
}