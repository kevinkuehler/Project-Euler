/*
Project Euler Problem 49
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

****************************************************************************************

Prompt:
The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330,
is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the
4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes,
exhibiting this property, but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence?
*/
#include <iostream>
#include <cstring>
#include <string>
#define N 10000
using namespace std;
bool* sieve_erato(unsigned int);
bool is_perm_4_dig(int, int, int);

int main() {
    /*
    * Assumptions: Start of unkown sequence is greater than start of given sequence.
    * We iterate through the 4 digit numbers (i) and, for each prime,
    * we enter another loop that also filters non-primes greater than i (j).
    * Using i and j, we can find the third number of the sequence by
    * doing [j-i] + j (k). j-i is the sequence difference and j is the offset.
    * If k is prime and i, j, and k are permutations we are finished.
    */
    auto sieve = sieve_erato(N-1);
    string prime_perm_seq;
    int i = 1488;
    do {
        if(sieve[i]) {
            int k;
            for(int j = i+2; (k=j+j-i) < N; j+=2)
                if(sieve[j] && sieve[k] && is_perm_4_dig(i,j,k))
                    prime_perm_seq = to_string(i) + to_string(j) + to_string(k);
        }
        i++;
    } while(prime_perm_seq.empty());

    cout << prime_perm_seq << endl;

    delete [] sieve;
    return 0;
}

/*
For each digit in a, b, and c the bits are set in its respective mask.
Returns true if the three masks are equal, meaning a, b, and c are permutations.
NOTE: Only works if a, b, and c are 4 digit numbers.
*/
bool is_perm_4_dig(int a, int b, int c) {
    int a_mask, b_mask, c_mask;
    a_mask = b_mask = c_mask = 0;
    for(int i = 0; i < 4; i++) {
        a_mask |= 1 << (a % 10);
        b_mask |= 1 << (b % 10);
        c_mask |= 1 << (c % 10);
        a/= 10; b/=10;  c/=10;
    }
    return a_mask == b_mask && a_mask == c_mask; // transitive
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





