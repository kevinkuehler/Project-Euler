/*
Project Euler Problem 39
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

***************************************************************************

Prompt:
If p is the perimeter of a right angle triangle with integral length sides,
{a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p <= 1000, is the number of solutions maximised?
*/
#include <iostream>
#include <math.h>
#include <cmath>
#include <ctime>
#define N 1000
using namespace std;

int perimeter_right_tri(int, int);
int main()
{
    int PTABLE[N] = {0};

    for(int a = 499; a > 0; a--)
    {
        int b = 2, p = perimeter_right_tri(a,1);
        while(p <= N && b < a)
        {
            if(p != -1 )
                PTABLE[p-1]++;
            b++;
            p = perimeter_right_tri(a,b);
        }
    }

    int max_count = PTABLE[1], max_p = 2;
    for(int i = 2; i < N; i++)
    {
        if(PTABLE[i] > max_count)
        {
            max_count = PTABLE[i];
            max_p = i+1 ;
        }
    }
    cout << max_p << endl;
    return 0;
}

/*
Returns the perimeter of a right triangle.
Uses the formula p=a+b+c and the fact that
a^2+b^2= c^2 => c=sqrt(a^2+b^2).
Only returns integer values of p and -1 if it is a dec
*/
int perimeter_right_tri(int a, int b)
{
    double c  = sqrt(a*a+b*b), check ;
    return modf(c,&check) == 0 ? a+b+c : -1;
}



