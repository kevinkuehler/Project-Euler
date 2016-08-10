/*
Project Euler Problem 34
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

****************************************************************************************

Prompt:
145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.
*/
#include <iostream>
using namespace std;

int fact_digit_sum(int n);

int main() {
	const static int UPPERBOUND = 2540160; // 10^6 = 1,000,000 <= n <= 2,540,160 = 9!*7
	// NOTE: By approximation upper-bound is ~50000, which runs much faster
	int i = 10, sum = 0; 
	while (i <= UPPERBOUND) {
		if (i == fact_digit_sum(i)) sum += i;
		i++;
	}
	cout <<sum << endl;

	return 0; 
}
/*
Computes the sum of the factorial of n's digits.
n must have at least 2 digits.
Gets factorials from array to avoid extra computing.
*/
int fact_digit_sum(int n) {
	static int fact0to9[10] = { 1,1,2,6,24,120,720,5040,40320,362880 };
	int sum = 0;
	do {
		sum+= fact0to9[n % 10];
		n /= 10;
	} while (n > 0);
	return sum; 
}

