/*
Project Euler Problem 26
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

***************************************************************************************

Prompt:
A unit fraction contains 1 in the numerator. The decimal representation of the unit 
fractions with denominators 2 to 10 are given:

1/2	= 	0.5
1/3	= 	0.(3)
1/4	= 	0.25
1/5	= 	0.2
1/6	= 	0.1(6)
1/7	= 	0.(142857)
1/8	= 	0.125
1/9	= 	0.(1)
1/10	= 	0.1
Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. 
It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
*/

#include <iostream>
#include <unordered_map>
#define N 1000 

using namespace std;

struct {
	int n = 0;
	int periodlen = 0;
} typedef DEC;

int periodlen(int);
void checkLg(DEC*, int);

int main() {
	DEC d;
	for (int i = 2; i < N; i++)
		checkLg(&d, i);
	cout << d.n << endl; 

	return 0;
}
/*
	Sets d structure to the new largest period
*/
void checkLg(DEC* d, int n) {
	int templen = periodlen(n);
	if (templen > d->periodlen) {
		d->periodlen = templen;
		d->n = n;
	}
}
/*
	Finds period length of decimal value
		-non rep nums (e.g. 1/4 ~ 0.2500) will break from seq 0's
		-infinite rep numbs (e.g. 1/d ~ 0.c(a) ) will break from seq a's
*/
int periodlen(int d) {
	unordered_map<int,int> rem_map; // <remainder,position>

	int rem = 1, pos = 1; // count also serves as dec position
	while(1) {
		rem = (10 * rem) % d;
		if (rem_map.count(rem)) return pos - rem_map.at(rem);
		rem_map.insert(make_pair(rem, pos));
		pos++;
	}
	return -1; // unreachable
}
