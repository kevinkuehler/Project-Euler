#include <iostream>
#include <math.h>
#include <ctime>
using namespace std; 

bool circular_prime(int, int);
int b_10_rol(int, int);
bool* sieveEratosthenes(unsigned int);

auto sieve = sieveEratosthenes(999999);
int main() {
	clock_t begin= clock(); 
	int count = 13; // given

	int s = 100, digits = 3;
	do {
		int digitrng = s * 10;
		for (int i = s; i < digitrng; i++)
			if (circular_prime(i, digits)) count++;
		s *= 10;
		digits++;
	} while (s < 1000000);

	cout << count << endl;
	clock_t end = clock(); 

	cout << double(end - begin) / CLOCKS_PER_SEC << endl;
	return 0;
}
bool circular_prime(int n, int digits) {
	if (!sieve[n]) return false; 
	for (int i = 0; i < digits-1; i++) {
		n = b_10_rol(n, digits);
		if (!sieve[n]) return false;
	}
	return true;
}
int b_10_rol(int n, int digits) {
	int save = pow(10,digits-1);
	return (n % save)*10 + n /save;
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