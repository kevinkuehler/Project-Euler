/*
* Kevin Kuehler
* https://github.com/kevinkuehler/Project-Euler
*
* Project Euler Problem 76
* https://projecteuler.net/problem=76
*
*/

#include <iostream>
#include <cmath>
#define N 100

using namespace std; 

int main() {
	
	int memo[N + 1][N + 1] = { { 0 } };

	memo[1][0] = 1; // partitions(1) = 1
	
	/*
	* Uses dynamic programming. For any number k 
	* we have solved for, the solution is in memo[k][0]. 
	* All subproblemsfor k are stored in memo[k][1] --> 
	* memo[k][k - 1]. For example, suppose we want to 
	* know how many solutions there are to 3 + 1:
	* we go to index memo[4][3].
	*/
	for (int i = 2; i < N + 1; i++) {
		memo[i][1] = 1; // row of 1s

		for (int j = 2; j < i; j++) {
			if (j >= ceil(i / 2.0)) {
				// Subproblems are single digits,
				// so we get full solution at index 0.
				memo[i][j] = memo[i][j - 1] + memo[i - j][0];
			}
			else {
				// Subproblems are multiple digits, 
				// so we get the partial solution.
				memo[i][j] = memo[i][j - 1] + memo[i - j][j];
			}
		}

		memo[i][0] = memo[i][i - 1] + 1;
	}
	
	cout << memo[N][0] - 1 << endl;
	return 0; 
}