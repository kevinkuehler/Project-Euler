/*
Project Euler Problem 47
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

*****************************************************************************************************************

Prompt:
The first two consecutive numbers to have two distinct prime factors are:

14 = 2 * 7
15 = 3 * 5

The first three consecutive numbers to have three distinct prime factors are:

644 = 2^2 * 7 * 23
645 = 3 * 5 * 43
646 = 2 * 17 * 19.

Find the first four consecutive integers to have four distinct prime factors. What is the first of these numbers?
*/
#include <iostream>
#include <algorithm>
#define N 4
using namespace std;
int* sieve_fact_cnt(unsigned int);
int main() {
    auto facts = sieve_fact_cnt(200000);
    int count = 0, last = 1, i = 10;

    while(count != N-1) {
        if(facts[i] == N && facts[i] == last)
            count++;
        else
            count = 0;
        last = facts[i];
        i++;
    }
    cout << i-N << endl;

    delete [] facts;
    return 0;
}

/*
Returns integer array where all indices and values represent
a number and its distinct number of prime factors.
Starts with the first prime and increments all the values that
are divisible by it (only once so distinction is handled).
This process repeats with sequential primes until limit is reached.
*/
int* sieve_fact_cnt(unsigned int len) {
    int* countarr = new int[len + 1];
	fill_n(countarr,len,0);
    for (int i = 2; i <= len; i++)
        if (!countarr[i])
            for (int j = i; j <= len; j += i)
                countarr[j]++;
    return countarr;
}


