/*
Project Euler Problem 24
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

*******************************************************************************************************************

Prompt:
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits
1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order.
The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define N 1000000
using namespace std;
void next_lex_perm(vector<char>&, int);
int main() {
    vector<char> lex;

    for(int i = 0; i <= 9; i++)
        lex.push_back(i+'0');

    for(int i = 0; i < N-1; i++)
        next_lex_perm(lex,10);

    string str(lex.begin(), lex.end());
    cout << str << endl;
    return 0;
}
/*
Dijkstra's lexiographic permutation algorithm
*/
void next_lex_perm(vector<char>& v, int l) {
    int i = l-1;
    while (v[i-1] >= v[i])
        i = i-1;

    int j = l;
    while (v[j-1] <= v[i-1])
        j = j-1;

    swap(v[i-1], v[j-1]);
    i++;
    j = l;
    while (i < j) {
        swap(v[i-1], v[j-1]);
        i++;
        j--;
    }
}
