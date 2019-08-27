/*
Fuad Al Abir
November 1, 2018
check.cpp
program reads N numbers from two file and see if they matches of not
*/
/*
Header: iostream
Reason: Input/Output stream
Header: cstdlib
Reason: For functions rand and srand
Header: time.h
Reason: For function time, and for data type time_t
Header: fstream
Reason: Input/Output in file
*/
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>

using namespace std;

int main()
{
    int N;
    int i;
    char fileName1[100];
    char fileName2[100];
    int matched;
    int dosentMatched;

    i = 0;
    matched = 0;
    dosentMatched = 0;

    cout << "Enter N: ";
    cin >> N;
    cout << "Enter filename 1: ";
    cin >> fileName1;
    cout << "Enter filename 2: ";
    cin >> fileName2;

    ifstream ifile1;
    ifstream ifile2;
    ifile1.open(fileName1);
    ifile2.open(fileName2);
    while (i < N)
    {
        int temp1, temp2;
        ifile1 >> temp1;
        ifile2 >> temp2;
        if (temp1 == temp2)
        {
            matched++;
        }
        else
        {
            dosentMatched++;
            cout << temp1 << " " << temp2 << endl;
        }
        
        i++;
    }
    ifile1.close();
    ifile2.close();

    cout << "Matched: " << matched << " Dosen't Matched: " << dosentMatched << endl;

    return 0;

}