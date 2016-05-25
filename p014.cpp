/*
Project Euler Problem 14
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

*************************************************************************************
Prompt:

The following iterative sequence is defined for the set of positive integers:

n -> n/2 (n is even)
n -> 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

*/
#include <iostream>
#define N 1000000

struct {
	unsigned int num;
	int length;
} typedef COLLATZ;

int * cache; // stores collatz lengths to optimize program speed 

/*
	For a number n, the collatz length is calculated by
	setting n equal to 3*n+1 is the number is odd and n is divided
	by 2 if it is even. Length is summed up while n is not 1 (sequence ends).
*/
int collatzlen(unsigned int n) {
	int length = 1;
	while (n != 1) {
		if (n > N || cache[n] != -1) { // use cached length instead of recalculating
			n = (n % 2) ? 3*n + 1 : n /= 2;
			length++;
		}
		else {
			length += cache[n];
			break;
		}
	}
	return length;
}
int main()
{
	cache = new int[N + 1];
	memset(cache, -1, N); // intially set cache to an undefined length

	COLLATZ c; // used to store a length and an associated number
	c.length = -1;
	c.num = -1;

	for (auto i = 1; i < N; i++) {
		cache[i] = collatzlen(i); // cache each collatz length
		// check for new largest legnth
		if (cache[i] > c.length) { 
			c.length = cache[i];
			c.num = i;
		}
	}

	delete [] cache; 
	std::cout << c.num << std::endl;
	return 0;
}