/*
Project Euler Problem 32
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

***************************************************************************************

Prompt:
We shall say that an n-digit number is pandigital if it makes use of all the digits
1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, 
containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity 
can be written as a 1 through 9 pandigital.
*/
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std; 

bool is_pandigital_prod(int[3]);
int main() {
	const static int N = 10000;

	int products = 0; 
	int i = 1000; // only 4 digit product totals 9 digits
	for (; i < N; i++) {
		for (int j = 1; j <= (int)sqrt(i); j++) {
			if (!(i % j)) {
				int t[3] = { i,j,i / j };
				if (is_pandigital_prod(t)) {
					products += i;
					break; 
				}
			}
		}
	}
	cout << products << endl; 

	return 0;
}
/*
	Returns true if all three numbers in the
	array can be written as a 1 through 9 pandigital.
*/
bool is_pandigital_prod(int nums[3]) {
	bool check[9]; // table to prevent dup numbers
	memset(check, false, 9 * sizeof(bool));
	int count = 0; 
	for (int i = 0; i < 3; i++) {
		while(nums[i] > 0) {
			int t = (nums[i] % 10) - 1;
			if (check[t]) return false; 
			check[t] = true;
			count++;
			nums[i] /= 10;
		} 
	} 
	return count == 9;
}

