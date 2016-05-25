/*

Project Euler Problem 17
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

**************************************************************************************

If the numbers 1 to 5 are written out in words: 
one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) 
contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. 
The use of "and" when writing out numbers is in compliance with British usage.

*/
#include <iostream>

int findNumLetterSum(int num);
int singleDigit(int n);
int teens(int n);
int doubleDigit(int n);

const int OneThousand = 11;
const int Hundred = 7;

int main() {
	int sum = 0;

	for (auto num = 1; num < 1000; num++) 
		sum+=findNumLetterSum(num);
	
	std::cout << sum + OneThousand << std::endl;

	return 0;
}

int findNumLetterSum(int num) {
	if (num < 10) 
		return singleDigit(num);
	else if (num < 20) 
		return teens(num);
	else if (num < 100) 
		return  doubleDigit(((num % 100) / 10) * 10) + singleDigit(num % 10);
	else if (!(num % 100)) 
		return singleDigit(num / 100) + Hundred;
	else {
		int tens = num % 100;
		if (tens >= 10 && tens < 20)
			return singleDigit(num / 100) + (Hundred + 3) + teens(tens);
		else 
			return singleDigit(num / 100) + (Hundred + 3) + doubleDigit((tens / 10)* 10) + singleDigit(num % 10);
	}
}
int singleDigit(int n) {
	switch (n) {
		case 1: case 2: case 6: return 3;
		case 3: case 7: case 8: return 5;
		case 4: case 5: case 9: return 4;
		default: return 0;
	}
}

int teens(int n) {
	switch (n) {
		case 10: return 3;
		case 11: case 12: return 6;
		case 13: case 14: case 18: case 19:  return 8;
		case 15: case 16: return 7;
		case 17: return 9;
		default: return 0;
	}
}

int doubleDigit(int n) {
	switch (n) {
		case 10: return 3;
		case 20: case 30: case 80: case 90: return 6;
		case 40: case 50: case 60: return 5;
		case 70: return 7;
		default: return 0;
	}
}