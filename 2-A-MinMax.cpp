/*-----------------------------
    I N T R O D U C T I O N
-------------------------------
Fuad Al Abir
November 5, 2018
MaxMin.cpp
This program finds the MAXIMUM and MINIMUM among the values read from a text file, "input.txt"
Algorithms:
    1. Brute force
    2. Divide and conquer (Base case with Single Node, Base case with Single and Double Node)
Problem Source: Problem A, Cycle 2, CSE 2202 and Assignment 1, CSE 2201
Instructor: Biprodip Pal, Assistant Professor, RUET
*/

/*-----------------------------
    H E A D E R   F I L E S
-------------------------------
Header: iostream
Reason: Input/Output stream - cin, cout
Header: time.h
Reason: For function time() and for data type clock_t
Header: fstream
Reason: Input/Output in file - ifstream, ofstream
Header: math.h
Reason: For the function floor()
*/

#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
#include <cstdlib>

using namespace std;

/*-----------------------
    S T R U C T U R E 
-------------------------
Structure:  divData
Reason:     To return a pair of data, Maximum and Minimum from divide_and_conquer()
*/
struct divData {
    int max;
    int min;
};

/*-------------------------------------
    G L O B A L   V A R I A B L E S
---------------------------------------
Global Variable:    counterDCSingleBase
Reason:             Count the number of comparison for Single node Base
Global Variable:    counterDCDoubleBase
Reason:             Count the number of comparison for Single and Double node Base
*/
int counterDCSingleBase = 0;
int counterDCDoubleBase = 0;

/*-------------------------------------------------
    U S E R   D E F I N E D   F U N C T I O N S
---------------------------------------------------
Function:   divData divide_and_conquer_single_node_base(int data[], int left, int right)
Reason:     Divide the array in half and Conquer the MAXIMUM and MINIMUM values, One node exit
Function:   divData divide_and_conquer_double_node_base(int data[], int left, int right)
Reason:     Divide the array in half and Conquer the MAXIMUM and MINIMUM values, One and Two node exit
*/
divData divide_and_conquer_single_node_base(int data[], int left, int right);
divData divide_and_conquer_double_node_base(int data[], int left, int right);

int main()
{
    int size;                           // size of the array
    int MAX = 0;                        // set MAX to 0 initially
    int MIN = 0;                        // set MIN to 0 initially
    int counterBruteForce = 0;          // counter for Brute force algorithm

    cout << "Enter N: ";
    cin >> size;                    
    int data[size];                     // main array to find the triplets, data[]

    // input file stream, ifile - to read random data from the text file 'input.txt'
    ifstream ifile;
    // "input.txt" - random data stored text file - is openned
    ifile.open("input.txt");            
    // initialize iterator by -1, used in while loop
    int i = -1;
    while (i < size)
    {
        // data is being stored from the file "input.txt"
        ifile >> data[++i];
    }
    // "input.txt" is closed
    ifile.close();


    /*-------------------------------------
    A L G O R I T H M   1 - Brute force
    ---------------------------------------*/
    MAX = data[0];
    MIN = data[0];
    for (int i = 1; i < size; i++)
    {
        counterBruteForce++;
        if (data[i] > MAX){
            MAX = data[i];
        }

        counterBruteForce++;
        if (data[i] < MIN)
        {
            MIN = data[i];
        }
    }

    // total triplets found and time taken is printed in the console
    cout << "------------------------------------------\n\tBrute Force Algorithm\n------------------------------------------\n";
    cout << "Maximum: " << MAX << "\nMinimum: " << MIN << "\nNumber of comparisons: " << counterBruteForce << endl;
    
    
    /*---------------------------------------------------------------
    A L G O R I T H M   2 - Divide and Conquer (single node exit)
    ---------------------------------------------------------------*/

    divData mainDivOneExit = divide_and_conquer_single_node_base(data, 0, size - 1);
    
    cout << "------------------------------------------\n\tBase case with Single Node\n------------------------------------------\n";
    cout << "Maximum: " << mainDivOneExit.max << "\nMinimum: " << mainDivOneExit.min << "\nNumber of comparisons: " << counterDCSingleBase << endl;

    /*-------------------------------------------------------------------
        A L G O R I T H M   3 - Divide and Conquer (double node exit)
    -------------------------------------------------------------------*/

    divData mainDivTwoExit = divide_and_conquer_double_node_base(data, 0, size - 1);
    
    cout << "------------------------------------------\n  Base case with Single and Double Node\n------------------------------------------\n";
    cout << "Maximum: " << mainDivTwoExit.max << "\nMinimum: " << mainDivTwoExit.min << "\nNumber of comparisons: " << counterDCDoubleBase << endl;
}

divData divide_and_conquer_double_node_base(int data[], int left, int right)
{
    int length = right - left + 1;
    if (length == 1)
    {
        divData newDivData;
        newDivData.max = data[left];
        newDivData.min = data[left];
        return newDivData;
    }
    else if (length == 2)
    {
        divData newDivData;
        if (data[left] > data[right])
        {
            newDivData.max = data[left];
            newDivData.min = data[right];
            counterDCDoubleBase++;
        }
        else
        {
            newDivData.max = data[right];
            newDivData.min = data[left];
            counterDCDoubleBase++;
        }
        return newDivData;
    }

    else
    {
        int mid = left+(right-left)/2; 
        divData temp1 = divide_and_conquer_double_node_base(data, left, mid);
        divData temp2 = divide_and_conquer_double_node_base(data, mid+1, right);
        divData divDataReturn;
        
        if (temp1.max > temp2.max)
        {
            divDataReturn.max = temp1.max;
            counterDCDoubleBase++;
        }
        else
        {
            divDataReturn.max = temp2.max;
            counterDCDoubleBase++;
        }
        
        if (temp1.min < temp2.min)
        {
            divDataReturn.min = temp1.min;
            counterDCDoubleBase++;
        }
        else
        {
            divDataReturn.min = temp2.min;
            counterDCDoubleBase++;
        }
        return divDataReturn;
    }
}

divData divide_and_conquer_single_node_base(int data[], int left, int right)
{
    int length = right - left + 1;
    if (length == 1)
    {
        divData newDivData;
        newDivData.max = data[left];
        newDivData.min = data[left];
        return newDivData;
    }
    else
    {
        int mid = left+(right-left)/2; 
        divData temp1 = divide_and_conquer_single_node_base(data, left, mid);
        divData temp2 = divide_and_conquer_single_node_base(data, mid+1, right);
        divData divDataReturn;
        
        if (temp1.max > temp2.max)
        {
            divDataReturn.max = temp1.max;
            counterDCSingleBase++;
        }
        else
        {
            divDataReturn.max = temp2.max;
            counterDCSingleBase++;
        }

        if (temp1.min < temp2.min)
        {
            divDataReturn.min = temp1.min;
            counterDCSingleBase++;
        }
        else
        {
            divDataReturn.min = temp2.min;
            counterDCSingleBase++;
        }
        return divDataReturn;
    }
}
