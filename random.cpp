/*-----------------------------
    I N T R O D U C T I O N
-------------------------------
Fuad Al Abir
October 31, 2018
random.cpp
program creates a file name "input.txt"
and writes N number of random values in it
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
    int n;                      // variable declared to store number of random numbers
    int i;                      // iterative variable
    int min;                    // variable declared to store minimum random value to generate
    int max;                    // variable declared to store maximum random value to generate

    ofstream ofile;             // ofstream object declaration: ofile

    clock_t clock_time;         // clock_time stores clock_time in ms
    time_t random_seed;         // a variable of type time_t is declared, which holds seconds on clock
    time(&random_seed);         // get variable from system clock and store it in t
    srand(random_seed);         // pass random_seed as seed of rand()

    cout << "Enter N: ";        // prompt user to input N
    cin >> n;                   // set user input to n
    i = 0;                      // set i to 0
    min = -20000;               // set min of random range
    max = 20000;                // set max of random range

    // opening file imput.txt
    ofile.open("input.txt");
    // clock_time starts
    clock_time = clock();       
    while (i < n)
    {
        // writing N random numbers to file 'input.txt'
        ofile << min + rand() % (( max + 1 ) - min) << endl;
        i++;
    }
    // clock_time ends
    clock_time = clock() - clock_time;
    // closing file imput.txt
    ofile.close();
    // printing clock_time in sec
    cout << "time taken: " << clock_time * 1.0 / CLOCKS_PER_SEC << " seconds." << endl; 

    return 0;
}
