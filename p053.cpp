/*
Project Euler Problem 53
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

**************************************************************************************************

Prompt:
There are exactly ten ways of selecting three from five, 12345:

123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

In combinatorics, we use the notation, 5C3 = 10.

In general, nCr=n!/(r!(n-r)!) ,where r ≤ n, n! = n×(n−1)×...×3×2×1, and 0! = 1.

It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.

How many, not necessarily distinct, values of  nCr, for 1 ≤ n ≤ 100, are greater than one-million?
*/
#include <iostream>
#define L 1000000
using namespace std;

long fact(int );
long fact_c(int, int);
long comb(int, int) ;
int main() {
    /*
    * Loops with n starting at 100 backwards until 23 (given).
    * We start by finding nCr from rH = n-2 and then rL = 0
    * until nCr is greater than 1 million. With rL > 1,000,000
    * and rH > 1,000,000, then rL <= x <= rH will necessarily
    * be greater than 1 million for all x. Therefore we sum the
    * number of values between rL and rH for all n.
    */
    int total = 0;
    for(int n = 100; n > 22; n--) {

        int rH = n-1, rL = -1;

        while(comb(--rH,n) < L+1) { }
        while(comb(++rL,n) < L+1) { }

        total+= rH - rL + 1;
    }
    cout << total << endl;

    return 0;
}

// Calculates the factorial of x.
// Returns x*(x-1)*(x-2)*...*2*1.
long fact(int x) {
    long total = 1;
    for(int i = x; i > 1; i--)
        total*=i;
    return total;
}

// Factorial fraction calcualtor, i.e. x!/c!, with c <= x,
// so x will multiply numbers from x*(x-1)*(x-2)*...*c+1*c
// instead of going back to 0 like a regular factorial.
// For example 5!/3! = (5*4*3*2*1)/3*2*1, so only 5*4 is computed.
// Utilized in combinations function to avoid integer overflow.
long fact_c(int x, int c) {
    long total = 1;
    for(int i = x; i > c; i--)
        total*=i;
    return total;
}

// Implementation of nCr=n!/(r!(n-r)!).
//Cancels n! with the greater of r! and (n-r)!.
long comb(int r, int n) {
    return (r > n-r) ? fact_c(n,r) / fact(n-r) :
     fact_c(n,n-r) / fact(r);
}
