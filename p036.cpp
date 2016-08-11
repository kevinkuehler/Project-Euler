/*
Project Euler Problem 36
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

************************************************************************************************

Prompt:
The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)
*/
#include <iostream>
#define MASK 19 // 999,999 has 20 bits
#define N 1000000
using namespace std; 

bool is_palindrome(int, int);
bool is_bin_palindrome(int );
int highest_bit(int, int);
bool is_set(int, int);
int main()
{
	int sum = 0;
	for (int i = 1; i < N; i++) 
		if (is_palindrome(i,10) && is_bin_palindrome(i)) sum+=i;
	cout << sum << endl;
	return 0;
}
/*
Reverses a number and checks if it is equal 
to the original, making it palindromic.
*/
bool is_palindrome(int n, int b) {
	int orig = n, rev = 0;
	while (n > 0)
	{
		rev = rev * b + (n % b);
		n /= b;
	}
	return orig == rev;
}
/*
Checks if a number is a palindrome by comparing the bits.
Optimized so it runs faster than is_palindrome method with b = 2.
*/
bool is_bin_palindrome(int n) {
	int i = 0, j = highest_bit(n, MASK);
	while (i < j) {
		if (is_set(n, i) != is_set(n, j)) return false ;
		i++;	j--;
	}
	return true; 
}
/*
Returns true if the bit at index p
is set to 1.
*/
bool is_set(int n, int p) {
	return (n & (1 << p)) ? true : false;
}
/*
Returns the highest set bit of a number. 
mask_len must >= bits in v. 
*/
int highest_bit(int n, int mask_len) {
	int mask = 1 << mask_len;
	for (int bitIndex = mask_len; bitIndex >= 0; bitIndex--) {
		if ((n & mask) != 0) return bitIndex;
		mask >>= 1; 
	}
	return -1;
}

