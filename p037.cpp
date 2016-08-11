/*
Project Euler Problem 37
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

*************************************************************************************
Prompt:
The number 3797 has an interesting property. Being prime itself, it is possible to 
continuously remove digits from left to right, and remain prime at each stage: 
3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right 
and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
*/
#include <iostream>
using namespace std; 

bool truncatable_prime(int n);
bool* sieveEratosthenes(unsigned int sievelen);
int main() {
	int count = 0, i = 10, sum = 0;

	do {
		if (truncatable_prime(i)) {
			count++;
			sum += i;
		}
		i++;
	} while (count != 11);

	cout << sum << endl;
	return 0; 
}
/*
Checks if number is a truncatable prime. 
Simple division gets right->left truncates.
Modulo times its dec place + old val gets right->left truncates
Returns true if all truncated possibilities are prime.
*/
auto sieve = sieveEratosthenes(800000);
bool truncatable_prime(int n) {
	if (!sieve[n]) return false; 

	int d_place = 1, c1= 0;
	while (n > 10) {
		c1 = d_place*(n % 10) + c1;
		int c2 = n /= 10;
		if (!sieve[c1] || !sieve[c2]) return false; 
		d_place *= 10;
	}
	return true;
}

/*
Sieve of Eratosthenes.
Returns boolean array where all primes are set to true.
*/
bool* sieveEratosthenes(unsigned int sievelen) {
	bool* primearr = new bool[sievelen + 1];
	memset(primearr, true, sizeof(bool) * sievelen);
	primearr[1] = false;
	for (auto i = 2; i*i < sievelen; i++) {
		if (primearr[i]) {
			for (auto j = i*i; j <= sievelen; j += i)
				primearr[j] = false;
		}
	}
	return primearr;
}