/*
Project Euler Problem 20
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

*****************************************************************************

Prompt:
n! means n * (n - 1) * ... * 3 * 2 * 1

For example, 10! = 10 * 9 * ... * 3 * 2 * 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/
#include <iostream>
#include <vector>

using namespace std;

#define N 100
typedef vector<int>::iterator V_I;
int sumdigits(int n);
int checkcarry(V_I v);

int main() {
	vector<int> fact;
	fact.push_back(2); // !2 = 2

	for (int i = 3; i <= N; i++) {
		int carry = 0;
		for (auto it = fact.begin(); it != fact.end(); it++) {
			*it = *it * i + carry;
			carry = checkcarry(it);
		} 
		if (carry) fact.push_back(carry);
	}
	
	int sum = 0;
	for (auto it = fact.rbegin(); it != fact.rend(); it++)
		sum += sumdigits(*it);
	cout << sum << endl;

	return 0;
}

/* Checks if vector index is > 1000, requiring a carry */
int checkcarry(V_I v) {
	int carry = 0;
	if (*v > 999) {
		carry = *v / 1000;
		*v %= 1000;
		return carry;
	}
	else
		return carry;
}

/* Breaks up n into individual digit and returns the sum */
int sumdigits(int n) {
	if (n > 99) 
		return n / 100 + n % 100 / 10 + n % 10;
	else if (n > 9) 
		return n / 10 + n % 10;
	else 
		return n;
}