/*-----------------------------
    I N T R O D U C T I O N
-------------------------------
Fuad Al Abir
November 1, 2018
mergeSort.cpp
Objective:  This program reads K random numbers from a file named "input.txt"
            and writes sorted numbers into a new file named "output_mergeSort.txt"
Sorting algorithms: MERGE SORT
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

void merge(int data[], int left, int mid, int right)
{
    int i, j, k;
    int size1 = mid - left + 1;
    int size2 = right - mid;

    int left_data[size1];
    int right_data[size2];

    for (i = 0; i < size1; i++)
    {
        left_data[i] = data[left + i];
    }
    for (i = 0; i < size2; i++)
    {
        right_data[i] = data[mid + 1 + i];
    }
    i = 0;
    j = 0;
    k = left;
    while (i < size1 && j < size2)
    {
        if (left_data[i] <= right_data[j])
        {
            data[k] = left_data[i];
            i++;
        }
        else
        {
            data[k] = right_data[j];
            j++;
        }
        k++;
    }
    while (i < size1)
    {
        data[k] = left_data[i];
        i++;
        k++;
    }
    while (j < size2)
    {
        data[k] = right_data[j];
        j++;
        k++;
    }
}

void mergeSort(int data[], int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left)/2;     // same as (left+rirht)/2, but avoids overflow for large left and right
        mergeSort(data, left, mid);
        mergeSort(data, mid+1, right);

        merge(data, left, mid, right);
    }
}

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

    /*-------------------------
        M E R G E   S O R T
    --------------------------*/
    mergeSort(data, 0, K - 1);

    // clock_time stops
    clock_time = clock() - clock_time;

    ofstream ofile;
    i = 0;
    ofile.open("output_mergeSort.txt");
    while(i < K)
    {
        ofile << data[i++] << endl;
    }
    ofile.close();

    // prints time needed for the Merge sort Algorithm
    cout << "time taken (for merge sort): " << clock_time * 1.0 / CLOCKS_PER_SEC << " seconds." << endl; 

    return 0;
}
