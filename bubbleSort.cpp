/*-----------------------------
    I N T R O D U C T I O N
-------------------------------
Fuad Al Abir
October 31, 2018
bubbleSort.cpp
Objective:  This program reads K random numbers from a file named "input.txt"
            and writes sorted numbers into a new file named "output_bubbleSort.txt"
Sorting algorithms: BUBBLE SORT
Problem Source: Problem A, Cycle 1, CSE 2202: Sessional based on CSE 2201.
Instructor: Biprodip Pal, Assistant Professor, RUET
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
    int K;                      // variable declared to store number of random numbers
    int i;                      // iterative variables i
    int j;                      // iterative variables j
    int k;                      // iterative variables k
    int temp;                   // temporary container
    clock_t clock_time;         // clock tick variable
    ifstream ifile;             // input file stream
    ofstream ofile;             // output file stream
    
    
    cout << "Enter K: ";
    cin >> K;
    int data[K];
    i = 0;

    // "input.txt" openned
    ifile.open("input.txt");
    while(i < K)
    {
        // popularize data[] from the file "input.txt"
        ifile >> data[i++];     
    }
    // "input.txt" closed
    ifile.close();

    // clock_time starts
    clock_time = clock();

    /*---------------------------
        B U B B L E   S O R T
    ----------------------------*/
    for (i = 0; i < K - 1; i++)
    {
        for (j = i + 1; j < K; j++)
        {
            if (data[i] > data[j])
            {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    
    // clock_time stops
    clock_time = clock() - clock_time;

    i = 0;
    ofile.open("output_bubbleSort.txt");
    while(i < K)
    {
        ofile << data[i++] << endl;
    }
    ofile.close();

    // prints time needed for the Bubble sort Algorithm
    cout << "time taken (for bubble sort): " << clock_time * 1.0 / CLOCKS_PER_SEC << " seconds." << endl; 

    return 0;
}
