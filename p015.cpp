/*
Project Euler Problem 15
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

*****************************************************************************

Prompt:
Starting in the top left corner of a 2×2 grid, and only being able to move to 
the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?
*/
#include <iostream>

#define N 21

void initGrid(unsigned long long [N][N]);
void setGridNums(unsigned long long [N][N]);

int main()
{
	unsigned long long arr[N][N];
	// set outer elements to 1
	initGrid(arr);
	// Sets path numbers
	setGridNums(arr);
	// The last index has the maximum number of routes.
	std::cout << arr[N - 1][N - 1] << std::endl;

}
/*
Lines top and left side of the grid with 1's, 
i.e. there is only one path we can take
to get to any of the places with a 1.

1 1 1 ... 1
1 ? ? ... ?
1 ? ? ... ?
. . . ... .
. . . ... .
. . . ... .
1 ? ? ... ?

*/
void initGrid(unsigned long long grid[N][N]) {
	for (int i = 0, j = 0; i < N; i++) 
		grid[i][j] = 1;
	for (int i = 0, j = 0; i < N; i++) 
		grid[j][i] = 1;
}
/* Sets number of paths to each index in the grid. Uses the fact that
   the path to each index is the sum of the indices one unit to the 
   left of it and one unit above it.

   NOTE: Grid must be initialized for this to work.
*/
void setGridNums(unsigned long long grid[N][N]) {
	for (unsigned int i = 1; i < N; i++) {
		for (unsigned j = 1; j < N; j++) {
			grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
		}
	}
}