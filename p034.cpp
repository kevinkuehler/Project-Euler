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

int fact(int n);
int fact_digit_sum(int n);

int main() {
	const static int UPPERBOUND = 2540160; // 10^6 = 1,000,000 <= n <= 2,540,160 = 9!*7

	int i = 10, sum = 0; 
	while (i <= UPPERBOUND) {
		if (i == fact_digit_sum(i)) sum += i;
		i++;
	}
	cout <<sum << endl;
	return 0; 
}
/*
Computes the sum of the factorial of a n's digits.
n must have at least 2 digits
*/
int fact_digit_sum(int n) {
	int sum = 0;
	do {
		sum+= fact(n % 10);
		n /= 10;
	} while (n > 0);
	return sum; 

}
/*
Iteratively computes factorial of an integer n
*/
int fact(int n) {
	int f = 1;
	for (int i = 1; i <= n; i++)
		f *= i;
	return f;
}
