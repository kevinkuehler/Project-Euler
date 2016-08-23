/*
Project Euler Problem 43
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

***********************************************************************************************************************

Prompt:
The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order,
but it also has a rather interesting sub-string divisibility property.

Let d(1) be the 1st digit, d(2) be the 2nd digit, and so on. In this way, we note the following:

    - d(2)d(3)d(4)=406 is divisible by 2
    - d(3)d(4)d(5)=063 is divisible by 3
    - d(4)d(5)d(6)=635 is divisible by 5
    - d(5)d(6)d(7)=357 is divisible by 7
    - d(6)d(7)d(8)=572 is divisible by 11
    - d(7)d(8)d(9)=728 is divisible by 13
    - d(8)d(9)d(10)=289 is divisible by 17

Find the sum of all 0 to 9 pandigital numbers with this property.
*/
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int almost_pandigital( long);
int unflipped(int);
long substr_divisibility(int, int, string);
int main()
{
    long sum = 0;
    for(int i = 17; i < 1000; i++)
        if(i % 17 == 0)
            sum+=substr_divisibility(i/10, 0, to_string(i % 10));

    cout << sum << endl;
    return 0;
}


/*
Recursively finds the sum of pandigital numbers where
d(2)d(3)d(4), d(3)d(4)d(5),d(5)d(6)d(7), etc are divisible by consecutive
prime numbers, beginning with 2. Requires d(8)d(9)d(10).
*/
long substr_divisibility(int n, int pindex, string save) {
    static int primes[6] = {13,11,7,5,3,2};

    if(pindex > 5) {
        int s = stoi(to_string(n).append(save)), miss;
        if( (miss = almost_pandigital(s)) != -1)
            return miss*pow(10,9)+s; //leftmost digit
        return 0 ;
    }
    long sum = 0;
    for(int i = 0; i < 10; i++) {
        int t = i*100 + n;
        if(t % primes[pindex] == 0)
            sum+=substr_divisibility(t/10,pindex+1,to_string(t%10).append(save));
    }

    return sum;
}

/*
Sees if a number is just one digit
away from being pandigital.
Works with missing digits only, not dups.

TODO: ADD functionality for 0's and filter in call
*/
int almost_pandigital( long n) {
	int mask = 0;
	while (n > 0) {
		int check = mask;
		mask |= (1 << (n % 10));
		if (check == mask)
			return -1; // dups
		n /= 10;
	}
	return unflipped(mask);
}
/*
Returns int value of a different
perms of 1 unflipped bit in 2^10
*/
int unflipped(int mask) {
    switch(mask) {
        case 1021 : return 1;    // bit 1
        case 1019 : return 2;    // bit 2
        case 1015 : return 3;    // bit 3
        case 1007 : return 4;    // etc..
        case 991 : return 5;
        case 959 : return 6;
        case 895 : return 7;     //....
        case 767 : return 8;
        case 511 : return 9;     // bit 9
        default : return -1;
    }
}
