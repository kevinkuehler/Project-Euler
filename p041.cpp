/*
Project Euler Problem 41
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

********************************************************************************************************

Prompt:
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once.
For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool is_prime(unsigned int);
int vtoi(vector<char>&);
int largest_prime_perm(vector<char>&);
int main()
{
    // init vector
    vector<char> pan;
    for(int i = 1; i <= 9; i++)
        pan.push_back(i +'0');

    /*
    Find largest pandigital prime.
    Starts by checking all permutations of 123456789,
    then 12345678, 1234567, etc. until first prime is found.
    */
    int largest_pp;
    do {
        largest_pp = largest_prime_perm(pan);
        pan.pop_back();
    } while(largest_pp == -1 );

    cout << largest_pp << endl;
    return 0;
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

/*
Converts a vector of char to an int (l->r)
*/
int vtoi(vector<char>& v) {
    int convert = 0, place = 1;
    for(auto it = v.rbegin(); it != v.rend(); it++, place*=10)
        convert+= ((*it) - '0')* place;
    return convert;
}

/*
Returns the largest prime permutation in the
char vector p. If none of the permutations
are prime -1 is returned.
*/
int largest_prime_perm(vector<char>& p) {
    int largest = -1;
    do {
        int t = vtoi(p);
        if(is_prime(t))
           largest = max(t,largest);
  } while (next_permutation(p.begin(), p.end()) );
  return largest;
}
