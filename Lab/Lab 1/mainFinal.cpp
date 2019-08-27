/*-----------------------------
    I N T R O D U C T I O N
-------------------------------
Fuad Al Abir
October 31, 2018
zeroTriplet.cpp
This program finds the triplets from a text file whose sum is equal to zero.
Algorithm(s): 
    1. Brute force algorithm using three nested loops; Complexity - O(n^3)
    2. Better implementation using Merge Sort and Binary Search; Complexity - O(n^2logn)
    3. Final (best so far) implementation using Merge Sort and Const Search; Complexity - O(n^2)
Problem Source: Problem B, Cycle 1, CSE 2202 and Assignment 1, CSE 2201
Instructor: Biprodip Pal, Assistant Professor, RUET
*/

/*-----------------------------
    H E A D E R   F I L E S
-------------------------------
Header: iostream
Reason: Input/Output stream - cin, cout
Header: fstream
Reason: Input/Output in file - ifstream, ofstream
Header: time.h
Reason: For function time() and for data type clock_t
Header: math.h
Reason: For the function floor()
*/

#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>

using namespace std;

/*-------------------------------------------------
    U S E R   D E F I N E D   F U N C T I O N S
---------------------------------------------------
Function: mergeSort()
Reason: To sort the data[] using Marge Sort algorithm
Function: merge()
Reason: To merge the sub-arrays, is called from mergeSort()
Function: biSearch()
Reason: Search for the value searchNum in data[] using Binary Search
*/

void mergeSort(int data[], int left, int right);
void merge(int data[], int left, int mid, int right);
int biSearch (int data[], int searchNum, int size);

int main()
{
    clock_t t;                          // clock ticks, returned by clock()

    int size;                           // size of the array
    int counterBruteForce = 0;          // triplet counter for Brute force algorithm
    int counterBisearch = 0;            // triplet counter for Improved Binary Search algorithm
    int counterConst = 0;               // triplet counter for Improved Constant Search algorithm

    cout << "Enter N: ";
    cin >> size;                    
    int data[size];                     // main array to find the triplets, data[]

    ifstream ifile;                     // input file stream, ifile - to read random data from the text file 'input.txt'
    ofstream ofile_brute_force;         // to store triplets found using algorithm 1 in a text file, named "output_brute_force.txt"
    ofstream ofile_binary_search;       // to store triplets found using algorithm 2 in a text file, named "output_binary_search.txt"
    ofstream ofile_const_search;        // to store triplets found using algorithm 3 in a text file, named "output_const_search.txt"

    // "input.txt" - random data stored text file - is openned
    ifile.open("input.txt");            
    // initialize iterator by -1, used in while loop
    int i = -1;
    while(i < size)
    {
        // data is being stored from the file "input.txt"
        ifile >> data[++i];
    }
    // "input.txt" is closed
    ifile.close();


    /*-----------------------------------------
        A L G O R I T H M   1 - Brute force
    -----------------------------------------*/
    // "output_three_loop.txt" is openned
    ofile_brute_force.open("output_brute_force.txt");
	// clock starts for algorithm 1
    t = clock();
    // nested loop of order three occurs the complexity O(n^3)
    for (int i = 0; i < size - 2; i++)
    {
        for (int j = i + 1; j < size - 1; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                if(data[i] + data[j] + data[k] == 0)
                {
                    // if triplets found, counterBruteForce is incremented by 1
                    // triplets stored in the text file
                    counterBruteForce++;
                    ofile_brute_force << data[i] << " " << data[j] << " " << data[k] << endl;
                }
            }
        }
    }
    // clock stops for algorithm 1
    t = clock() - t;
    // "output_three_loop.txt" is closed            
    ofile_brute_force.close();
    // number of triplets found and time taken is printed in the console
    cout << "Brute force triplet count: " << counterBruteForce << "\ntime for n^3: " << t*1.0/CLOCKS_PER_SEC << " seconds" << endl;

    /*----------------------------------------------------------------
        A L G O R I T H M   2 - using Merge Sort and Binary Search
    ----------------------------------------------------------------*/
    // mergeSort() is called
    mergeSort(data, 0, size - 1);
    // "output_binary_search.txt" is openned
    ofile_binary_search.open("output_binary_search.txt");
    // clock starts for algorithm 2
    t = clock();
    // two data is mapped by nested loops of order 2
    // thirt data of the triplet is found by binary search
    for(int i = 0; i < size - 2; i++)
    {
        for(int j = i + 1; j < size - 1; j++)
        {
            int searchNum = -(data[i] + data[j]);
            // B I N A R Y   S E A R C H for searchNum
            if(biSearch(data, searchNum, size))
            {
                // if triplets found, counterBisearch is incremented by 1
                // triplets stored in the text file
                counterBisearch++;
                ofile_binary_search << data[i] << " " << data[j] << " " << searchNum << endl;
            }
        }
    }
    // clock starts for algorithm 2
    t = clock() - t;
    // "output_binary_search.txt" is closed
    ofile_binary_search.close();
    // number of triplets found and time taken is printed in the console
    cout << "BinarySearch triplet Count: " << counterBisearch << "\ntime n^2logn: " << t*1.0/CLOCKS_PER_SEC << " seconds" << endl;

    /*---------------------------------------------------------------
        A L G O R I T H M   3 - using mergeSort and Custom Search
    ---------------------------------------------------------------*/
    ofile_const_search.open("output_const_search.txt");
    // clock starts for algorithm 3
    t = clock();
    for(int i = 0; i < size - 2; i++)
    {
        int left = i + 1;
        int right = size - 1;
        while(left < right)
        {
            if (data[i] + data[left] + data[right] == 0) 
            { 
                counterConst++;
                ofile_const_search << data[i] << " " << data[left] << " " << data[right] << endl;
                left++;
                right--;
            } 
            else if (data[i] + data[left] + data[right] < 0) 
                left++;
            else
                right--; 
        }
    }
    // clock starts for algorithm 3
    t = clock() - t;
    // "output_const_search.txt" is closed
    ofile_const_search.close();
    // number of triplets found and time taken is printed in the console
    cout << "Const search triplet Count: " << counterBisearch << "\ntime n^2: " << t*1.0/CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}

/*------------------------
    M E R G E  S O R T
--------------------------*/
void mergeSort(int data[], int left, int right) 
{ 
    if (left < right) 
    { 
        int mid = left+(right-left)/2; 
        mergeSort(data, left, mid);
        mergeSort(data, mid+1, right);
        merge(data, left, mid, right); 
    } 
} 

/*------------------------------------
    M E R G E  S U B - A R R A Y S
--------------------------------------*/
void merge(int data[], int left, int mid, int right) 
{ 
    int i, j, k;
    int size1 = mid - left + 1;
    int size2 =  right - mid;
  
    int left_data[size1];
    int right_data[size2]; 
  
    for (i = 0; i < size1; i++)
    { 
        left_data[i] = data[left + i];
    }
    for (j = 0; j < size2; j++) 
    {
        right_data[j] = data[mid + 1 + j];
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

/*-------------------------------
    B I N A R Y   S E A R C H
---------------------------------*/
int biSearch (int data[], int searchNum, int size)
{
    int location = 0;
    int start = 0;
    int end = size - 1;
    while(start < end)
    {
        int mid = floor((start + end) / 2);
        if(searchNum > data[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    if(searchNum == data[start])
    {
        location = start;
    }
    else location = 0;
    return location;
}