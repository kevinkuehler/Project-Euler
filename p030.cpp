/*
Project Euler Problem 30
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

***********************************************************************************************************
Prompt:
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

1634 = 1^4 + 6^4 + 3^4 + 4^4
8208 = 8^4 + 2^4 + 0^4 + 8^4
9474 = 9^4 + 4^4 + 7^4 + 4^4
As 1 = 1^4 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
*/

#include <iostream>
#include <math.h>
using namespace std; 

int powerDigitSum(int n, int e);

int main() {
	const static int pow = 5, L = 1000000;
	int sum = 0;
	for (int i = 2; i < L; i++) 
		if (i == powerDigitSum(i, pow)) sum+= i;

	cout << sum << endl;
	return 0; 
}


int powerDigitSum(int n, int e) {
	int sum = 0;
	while (n > 0) {
		sum += pow(n % 10, e);
		n /= 10; 
	}
	return sum;
}