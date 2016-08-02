/*
Project Euler Problem 27
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

*************************************************************************************

Prompt:
Considering quadratics of the form:

	n^2+an+b, where |a|<1000 and |b|<=1000

	where |n| is the modulus/absolute value of n
	e.g. |11|=11 and |-4|=4

Find the product of the coefficients, a and b, for the quadratic expression that 
produces the maximum number of primes for consecutive values of n, starting with n=0.
*/
#include <iostream>
using namespace std; 

bool* sieveEratosthenes(unsigned int);
int quadratic(int, int, int);
int consecutive_primes(int, int, bool*);

int main() {
	static const int N = 1000;

	auto sieve = sieveEratosthenes(20000);
	int max_a, max_b, maxprimes = -1;
	
	for (int a = -N+1; a < N; a++) {
		for (int b = -N; b <= N; b++) {
			if (sieve[b]) { // n=0=b
				int t = consecutive_primes(a,b,sieve);
				if (t > maxprimes) {
					maxprimes = t; 
					max_a = a; 
					max_b = b;
				}
			}
		}
	} 
	cout << max_a * max_b << endl;  
	
	return 0;
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
/*
	Generates values for n^2+an+b.
*/
int quadratic(int n, int a, int b) {
	return n*n + a*n + b;
}
/*
	Plugging a & b into eqn n^2+an+b,
	finds number of primes for consecutive values of n,
	starting with n = 0.
*/
int consecutive_primes(int a, int b, bool* sieve) {
	int q, n = -1;
	while ((q = quadratic(++n,a,b)) > 1 && sieve[q]) {}
	return n;
}
