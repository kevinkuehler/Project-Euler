/*
Project Euler Problem 33
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

***************************************************************************************

Prompt:
The fraction 49/98 is a curious fraction, as an inexperienced mathematician
in attempting to simplify it may incorrectly believe that 49/98 = 4/8, 
which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, 
less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, 
find the value of the denominator.
*/
#include <iostream>
using namespace std; 

bool is_anomalous(int, int);
int gcd(int, int );

int main() {
	int f_num = 1, f_denom = 1;
	for (int n = 11; n < 100; n++) {
		for (int d = n + 1; d < 100; d++) {
			if (is_anomalous(n, d)) {
				f_num *= n; 
				f_denom *= d;
			}
		}
	}
	cout << f_denom / gcd(f_num, f_denom) << endl;

	return 0;
}
/*
Returns true if fraction with numerator n 
and denominator d is anomalous. 
*/
bool is_anomalous(int n, int d) {
	if (!(d % 10) && !(n%10)) return false; // trivial
	double n1 = n / 10, n2 = n % 10, d1 = d / 10, d2 = d % 10;
	double match = (double)n / d;
	if (n1 == d1)
		return n2 / d2 == match;
	else if (n1 == d2) 
		return n2 / d1 == match;
	else if (n2 == d1) 
		return n1 / d2 == match;
	else if (n2 == d2) 
		return n1 / d1 == match; 
	return false; 

}
/*
	Returns greatest common divisor of two numbers.
*/
int gcd(int n1, int n2) {
	while (n1 != n2)
	{
		if (n1 > n2)
			n1 -= n2;
		else
			n2 -= n1;
	}
	return n1; 
}
