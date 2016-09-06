/*
Project Euler Problem 52
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

************************************************************************

Prompt:
It can be seen that the number, 125874, and its double, 251748, contain
exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x,
contain the same digits.

*/
#include <iostream>

using namespace std;

bool is_perm(int a, int b);
int main() {
    /*
    * For every number i we check if i, 2*i, 3*i, 4*i, 5*i, and 6*i
    * are permutations; we break when find a number that satifies this.
    * We can increment by 3 because i and 3*i must have the same digits
    * (and therefore the same sum) to be permutations, and the divisibility
    * rule for 3 states that the sum of a numbers digits must also be
    * divisible by 3, so i must be divisible by 3.
    */
    int i;
    for(i = 3; ; i+=3)
        if(is_perm(i,2*i) && is_perm(i,3*i) && is_perm(i,4*i) &&
         is_perm(i,5*i) && is_perm(i,6*i))
            break;
    cout << i << endl;
    return 0;
}

/*
For each digit in a and b the bits are set in its respective mask.
Returns true if a and b are the same length and if the masks are equal.
*/
bool is_perm(int a, int b) {
    int a_mask, b_mask;
    a_mask = b_mask = 0;
    while(a && b) {
        a_mask |= 1 << (a % 10);
        b_mask |= 1 << (b % 10);
        a/= 10; b/=10;
    }
    return a == b ? a_mask == b_mask : false;
}
