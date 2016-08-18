/*
Project Euler Problem 42
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

***********************************************************************************************************************

Prompt:
The nth term of the sequence of triangle numbers is given by, t(n) = 1/2*n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position and adding these values
we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t(10).
If the word value is a triangle number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'),
a 16K text file containing nearly two-thousand common English words, how many are triangle words?
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <math.h>
#define TRI(x) floor(sqrt(8*x+1)) == sqrt(8*x+1)
using namespace std;

int decode(string&);
int main() {

    string filestr;
    ifstream file("p042_words.txt");
    file >> filestr;

    /*
    File contents are stored in the string filestr.
    Using two sets of parenthesis as front and back
    delimiters, the relevant words are parsed, decoded
    and checked for triangularity. Counter is incremented
    for all triangle numbers.
    */
    size_t start = 0, end = 0;
    char delim = '\"';
    int count = 0;
	do {
		start = filestr.find(delim, start);
		if (start == string::npos) break;
		end = filestr.find(delim, start + 1);
		string token = filestr.substr(start + 1, end - start - 1);
		if (!token.empty())
            if(TRI(decode(token)))
                count++;
		start = end + 1;
    } while (start < filestr.length() && end < filestr.length());

    file.close();

    cout << count << endl;
    return 0;
}

/*
Converts string of cap letters to their corresponding
integer values (e.g. A=1, B=2, ... ,Y=25, Z=26)
and returns the sum of those values.
*/
int decode(string& w) {
    int value = 0;
    for(int i = 0; i < w.length(); i++)
        value +=w[i] - '@';
    return value;
}



