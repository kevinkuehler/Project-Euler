/*
Project Euler Problem 22
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

*****************************************************************************

Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over
five-thousand first names, begin by sorting it into alphabetical order. 
Then working out the alphabetical value for each name, multiply this value by its 
alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 
3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list.
So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/

#include <iostream>    
#include <algorithm>    
#include <vector>     
#include <string>
#include <fstream>

using namespace std; 

vector<string> extract(const string&, const string&, const string&);
int sumstr(const string&);

int main() {
	string filestr;
	ifstream file("p022_names.txt");
	file >> filestr; 

	auto names = extract(filestr, "\"", "\"");
	sort(names.begin(), names.end());

	unsigned int total = 0;
	for (auto it = names.begin(); it != names.end(); it++) 
		total += sumstr(*it)*(distance(names.begin(), it) + 1);

	cout << total << endl; 
	return 0;
}

/* 
	Extracts a string between two delimiter strings (supports varying occurrence) 
*/
vector<string> extract(const string& str, const string& delim, const string& delim2)
{
	vector<string> tokens;
	size_t start = 0, end = 0;

	do {
		start = str.find(delim, start);
		if (start == string::npos) break;
		end = str.find(delim, start + 1);
		string token = str.substr(start + 1, end - start - 1);
		if (!token.empty()) tokens.push_back(token);
		start = end + 1;
	} while (start < str.length() && end < str.length());

	return tokens; 
}
/* 
	Converts a string of capital letters to the int value of their place 
	in the alphabet. Returns the sum.
*/
int sumstr(const string& str) {
	int sum = 0;
	for (char c : str) 
		sum += (int)c - 64;
	return sum;
}