/*
Project Euler Problem 35
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

********************************************************************************

Prompt:
The number, 197, is called a circular prime because all rotations of the digits:
197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 
2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?
*/
#include <iostream>
#include <math.h>
using namespace std;

bool circular_prime(int);
int b_10_rol(int, int);
bool* sieveEratosthenes(unsigned int);

auto sieve = sieveEratosthenes(999999);
int main() {
	const static int N = 1000000;

	int count = 13, s = 100, digits = 3; // given
	
	for (int i = 100; i < N; i++) 
		if (circular_prime(i)) count++;

	cout << count << endl;
	return 0;
}
/*
Returns true if a n is circular prime,
meaning all rotations of n's digits are prime.
*/
bool circular_prime(int n) {
	if (!sieve[n]) return false;
	int r = log10(n); // n digits - 1
	for (int i = 0; i < r; i++) {
		n = b_10_rol(n, r);
		if (!sieve[n]) return false;
	}
	return true;
}
/*
Shifts a number n to the left once.
Digit in highest dec place moves to ones place.
*/
int b_10_rol(int n, int e) {
	int save = pow(10, e);
	return (n % save) * 10 + n / save;
}
/*
Sieve of Eratosthenes.
Returns boolean array where all primes are set to true.
*/
bool* sieveEratosthenes(unsigned int sievelen) {
	bool* primearr = new bool[sievelen + 1];
	memset(primearr, true, sizeof(bool) * sievelen);

	for (auto i = 2; i*i < sievelen; i++) {
		if (primearr[i]) {
			for (auto j = i*i; j <= sievelen; j += i)
				primearr[j] = false;
		}
	}
	return primearr;
}