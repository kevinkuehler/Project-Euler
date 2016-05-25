/*
Project Euler Problem 67
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

*****************************************************************************

Prompt:
By starting at the top of the triangle below and moving to adjacent numbers on the row below, 
the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom in p067_triangle.txt,
a 15K text file containing a triangle with one-hundred rows.
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std; 

#define R 100

int main() {
	vector< vector<int> > triangle;
	ifstream data;
	
	data.open("p067_triangle.txt");
	// Read row from file into vector, then store each row vector in the container vector.
	for (int i = 0; i < R; i++) {
		vector<int> row;
		for (int j = 0; j <= i; j++) {
			string num; // string for 2-digit #'s
			data >> num;
			row.push_back(stoi(num));
		}
		triangle.push_back(row);
	}
	data.close();

	// Starting with second-to-last row, (greatest) of the smallest possible triangles is solved
	// using the numbers in the row below it. Continues until the top. 
	for (int i = triangle.size()-2; i >= 0; i--) {
		for (int j = 0; j < triangle[i].size(); j++) 
			 triangle[i][j] = max(triangle[i][j] + triangle[i+1][j],
					triangle[i][j] + triangle[i+1][j+1]);
	}

	cout << "Maximum Path Sum: " << triangle[0][0] << endl;

	return 0;
}