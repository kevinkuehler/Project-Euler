/*
Project Euler Problem 46
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

****************************************************************************

Prompt:
It was proposed by Christian Goldbach that every odd composite number can be
written as the sum of a prime and twice a square.

9  = 7  + 2*12
15 = 7  + 2*22
21 = 3  + 2*32
25 = 7  + 2*32
27 = 19 + 2*22
33 = 31 + 2*12

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as
the sum of a prime and twice a square?
*/
#include <iostream>
using namespace std;
bool is_prime(unsigned int);
bool conjecture_holds(unsigned int);

int main() {

    /*
    * i must not be prime and the conjecture must fail
    * for the loop to terminate.
    */
    int i = 9;
    while( is_prime(i) || conjecture_holds(i))
        i+=2;

    cout << i << endl;
    return 0;
}

/*
Writing Goldbach's conjecture mathematically is c=p+2a^2, where
c is an odd composite number, p is any prime, and a is any number.
For Goldbach's conjecture to hold then c-2a^2=p.
Returns true if Goldbach's conjecture holds, false if not.
*/
bool conjecture_holds(unsigned int c) {
    int t, a = 1;
    do {
        t=c-2*a*a;
        if(is_prime(t))
            return true;
        a++;
    } while(t > 1);
    return false;
}

/*
Checks divisibility all the way up sqrt(n).
If no divisible numbers are found returns true.
First checks 2 and then only odd numbers.
*/
bool is_prime(unsigned int n) {
    if(n < 2 || n % 2 == 0)
        return false;

    for(int i = 3; i*i <= n; i+=2)
        if(n % i == 0)
            return false;

    return true;
}
