/*
Project Euler Problem 64
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

********************************************************************************************************

Prompt:
It can be seen that the sequence is repeating. For conciseness, we use the notation √23 = [4;(1,3,1,8)],
to indicate that the block (1,3,1,8) repeats indefinitely.

The first ten continued fraction representations of (irrational) square roots are:

√2=[1;(2)], period=1
√3=[1;(1,2)], period=2
√5=[2;(4)], period=1
√6=[2;(2,4)], period=2
√7=[2;(1,1,1,4)], period=4
√8=[2;(1,4)], period=2
√10=[3;(6)], period=1
√11=[3;(3,6)], period=2
√12= [3;(2,6)], period=2
√13=[3;(1,1,1,1,6)], period=5

Exactly four continued fractions, for N ≤ 13, have an odd period.

How many continued fractions for N ≤ 10000 have an odd period?
*/
#include <iostream>
#include <cmath>
#define N 10000
using namespace std;

int cont_fract(int s);
int main() {
    int odd_periods = 0;
    for(int i = 2; i < N + 1; i++)
        if(cont_fract(i) % 2)
            odd_periods++;

    cout << odd_periods << endl;

    return 0;
}

// An iterative version of the continued fraction algorithm.
// When a(n) is double the value of a(0) we know the period is complete.
// Returns the period length of s insofar as s is not a perfect square.
// In the case of a perfect square 0 will be returned, as the shortest
// period length is one.
int cont_fract(int s) {
    int a0 = floor(sqrt(s));
    if(a0*a0 == s)
        return 0;

    int m = 0, d = 1, a = a0, len = 0;
    do {
        m = d*a-m;
        d = (s-m*m) / d;
        a = floor( (a0 + m) / d );
        len++;
    } while(a != 2 * a0);
    return len;
}

