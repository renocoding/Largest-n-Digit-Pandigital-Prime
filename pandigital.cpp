// Title: pandigital.cpp
// Author: Reno Domel
// Date: 10/29/19
// Description: This program finds the largest n-digit pandigital number that is prime

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

/* Pre-Code Analysis

1 -- prime
1 + 2 = 3 -- divisible by 3
1 + 2 + 3 = 6 -- divisble by 3
1 + 2 + 3 + 4 = 10 -- not divisble by 3
1 + 2 + 3 + 4 + 5 = 15 -- divisble by 3
1 + 2 + 3 + 4 + 5 + 6 = 21 -- divisible by 3
1 + 2 + 3 + 4 + 5 + 6 + 7 = 28 -- not divisble by 3
1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 = 36 -- divisble by 3
1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 = 45 -- divisible by 3

Thus, the number whose individual digits sum up to a number divisible by 3 are
guaranteed not to be prime

We first check all 7-digit pandigital numbers, then 4-digit pandigital numbers

*/

bool isPrime(long);
bool isPandigital(long n);

int main()
{

    // initialize array to store all prime values
    long size = 10000000;
    vector <int> myVector(size,1);



    bool foundPrime = true; // this flag tells us if we marked out a non-prime in our iteration of p
    int p = 2; //this is the multiple being used in our sieve of Eratosthenes

    while (foundPrime == true)
    {

        foundPrime = false; // set flag to false (we are set to exit loop)
        int i = 2;
        while (i * p < size)
        {
            if (myVector[i*p] == 1) // found a non-prime
            {

                myVector[i*p] = 0; // make it zero
                foundPrime = true; // change flag to true because we marked a number out in this iteration
            }
            i++;

        }



        // this block of code changes our multiple p until we find a value that hasn't been crossed out
        p++;
        while (myVector[p] != 1)
        {

            p++;

        }

    }

    long primeIndex = 2; // start at two
    vector <long> myprimes(1000000,0);
    long mypInd = 0;


    // while loop that goes through the giant vector and finds values not crossed out
    while(primeIndex < size)
    {

        if (myVector[primeIndex] == 1)
        {

            myprimes[mypInd] = primeIndex; // store every prime number in a vector
            mypInd++;


        }

        primeIndex++;

    }


    long max = 0;



// -----Pandigital Part-----

    // loop through each prime number
    for (long i = 2; i < mypInd; i++)
    {
        long n = myprimes[i];

        // determine if it is pandigital
        if(isPandigital(n))
        {
                max = n;

        }

    }


    // display
    cout << "The max n-digit pandigital number that is prime: " << max << endl;

    return 0;
}

bool isPandigital(long n)
{
    string s = to_string(n);
    string permut = "1234567";
    if ((std::is_permutation (permut.begin(), permut.end(), s.begin())) == true)
        return true;
    else
        return false;
}
