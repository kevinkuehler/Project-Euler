/*
Project Euler Problem 50
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

**********************************************************************************************************************

The prime 41, can be written as the sum of six consecutive primes:
41 = 2 + 3 + 5 + 7 + 11 + 13

This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?
*/
#include <iostream>
#include <cstring>
#define N 1000000
using namespace std;
bool* sieve_erato(unsigned int);
int main() {
    /*
    * a) Create a sieve of prime numbers [0,999,999].
    * Starting with the lowest prime (2), b) we sum
    * the consecutive primes until the sum is
    * greater than 1 million. c) Then we go back one
    * number. If this number is a prime, then we
    * found the number with the largest consecutive
    * sequence and exit the loop; if not we
    * increment our starting prime and go to step b.
    */
    auto sieve = sieve_erato(N-1);
    int total, last, i = 2;
    do {
        if(sieve[i]) {
            total = 0;
            for(int j = i+1; total < N; j++) {
                if(sieve[j]) {
                    total+=j;
                    last = j;
                }
            }
        }
        i++;
    } while(!sieve[total-last]);
    cout << total-last <<  endl;
    delete [] sieve;
    return 0;

}

/*
Sieve of Eratosthenes algorithm. Returns boolean
array where all prime indicies are true.
Size of the array specified by caller. 
*/
bool* sieve_erato(unsigned int sievelen) {
	bool* primes = new bool[sievelen + 1];
	memset(primes, true, sizeof(bool)*sievelen);
	primes[0] = primes[1] = false;
	for (auto i = 2; i*i < sievelen; i++)
		if (primes[i])
			for (auto j = i*i; j <= sievelen; j+=i)
				primes[j] = false;
	return primes;
}
