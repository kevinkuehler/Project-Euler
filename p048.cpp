/*
Project Euler Problem 48
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

**************************************************************************

Prompt:
The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
*/
#include <iostream>
#define N 1000
using namespace std;

typedef long long LL;
LL digit_spow(int);
const LL lim = 10000000000;

int main() {
    LL ltd = 0;
    for(int i = 1; i <= N; i++) {
        ltd += digit_spow(i);
        ltd%=lim;
    }
    cout << ltd << endl;
    return 0;
}

/*
Starts with some number x and loops x times,
each time multiplying x by itself. After each multiplcation,
we mod x with our limit, because we want no more than 10 digits,
and it also prevents integer overflow.
*/
LL digit_spow(int x) {
    LL total = x;
    for(int i = 1; i < x; i++)
        total = total * x % lim;
    return total;
}

