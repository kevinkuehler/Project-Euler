/* 
* Kevin Kuehler
* https://github.com/kevinkuehler/Project-Euler
*
* Project Euler Problem 63
* https://projecteuler.net/problem=63
*
*/
#include <iostream> 
#include <cmath> 

using namespace std;

/* Uses the fact that ceil(log10(n)) gives 
* us the digits in some number n -- therefore 
* log10(n^p) is written as plog10(n).
*/
int digit_pow(int n) {
	int p = 0;
	while(++p <= ceil(p*log10(n))) { }
	return p - 1; 
}

/* Upper bound is 10 because 10^1 has 2 digits, 
* and this pattern becomes more pronounced as 
* the base increases. 
*/
int main() {
	int count = 0;
	for(int i = 2; i < 10; i++) 
		count += digit_pow(i);
	cout << count + 1 << endl;
	return 0; 
}


