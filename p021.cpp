/*
Project Euler Problem 21
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

********************************************************************************************************

Prompt:
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a /= b, 
then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110;
therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/
#include <iostream>
#define N 10000
using namespace std;

int main() {
	
	int sum = 0;
	int amicable[N] = { 0 }; // key=num and val=(sum of prop divisors)
	
	int amic = 220; // first amicable number
	
	while (amic < N) {
		int propDivisorSum = 0;
		for (int i = 1; i <= (amic/2); i++) 
			if (!(amic % i)) 
				propDivisorSum += i;

		if (propDivisorSum < N) { // ignore n > 10k 
			if (amicable[propDivisorSum] == amic)
				sum += propDivisorSum + amic;
			amicable[amic] = propDivisorSum;
		}
		amic++;
	}
	cout << sum << endl;
	return 0;
}