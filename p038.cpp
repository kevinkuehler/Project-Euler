/*
Project Euler Problem 38
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

*****************************************************************************************

Prompt:
Take the number 192 and multiply it by each of 1, 2, and 3:

192 * 1 = 192
192 * 2 = 384
192 * 3 = 576

By concatenating each product we get the 1 to 9 pandigital, 192384576. 
We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, 
giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed 
as the concatenated product of an integer with (1,2, ... , n) where n > 1?
*/
#include <iostream>
#include <algorithm>
using namespace std;
bool is19Pandigital(unsigned int);
int main() {
	int largest = 918273645; // given
	/*
	We start n at 9123 because our number needs to start with a 9 and
	have an end result of 9 digits. Using n >= 10000 will give us at least
	10 digits when p = 2, so range must be below 10000. We want our end result to start
	with a 9. 90 <= n <= 99 and 900 <=n <= 999 produce 11 digits for p=4 and p=3 respectively. 
	9000 <= n <= 9999 gives us 9 digits for p = 2, and we start where n*1 is 1->9 pandigital.
	*/
	for (int n = 9123; n <= 9876; n++) {
		int tmp = n * pow(10,5); // make room
		tmp += (n * 2); // 5 digits
		if (is19Pandigital(tmp))
			largest = max(largest, tmp);
	}
	cout << largest << endl;
	return 0; 
}
/*
Determines if number is pandigital by flipping
bits in mask to 1. The bits in mask should equal
the bits set by count.
*/
bool is19Pandigital(unsigned int n) {
	int mask, count;
	count = mask = 0;
	while (n > 0) {
		int check = mask;
		mask |= (1 << (n % 10 - 1));
		if (check == mask) 
			return false; // dups don't flip new bits
		n /= 10;
		count++;
	}
	return mask == (1 << count) - 1;
}