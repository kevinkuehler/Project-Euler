/*
Project Euler Problem 40
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

*********************************************************************************

Prompt:
An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If d(n) represents the nth digit of the fractional part,
find the value of the following expression.

d(1) * d(10) * d(100) * d(1000) * d(10000) * d(100000) * d(1000000)
*/
#include <iostream>
#include <vector>
#define N 1000000
using namespace std;

void append_parsed_int(vector<char>&, int);
int main()
{
    vector<char> champernowne;
    for(int i = 1; champernowne.size() < N+1; i++)
        append_parsed_int(champernowne,i);

    int prod = 1;
    for(int i = 10; i != N; i*=10)
        prod*=(champernowne[i-1]-'0');
    cout << prod << endl;
}
/*
Parses integer into characters and stores
them in the vector in order (l->r).
*/
void append_parsed_int(vector<char>& c, int n) {
    char stor[7];
    int i = 0;
    while(n > 0 ) {
        stor[i++] = (n%10)+'0';
        n/=10;
    }
    for(i--; i >= 0;i--)
        c.push_back(stor[i]);
}
