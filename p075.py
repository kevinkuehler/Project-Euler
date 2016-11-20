# Kevin Kuehler
# https://github.com/kevinkuehler/Project-Euler
#
# Project Euler Problem 75
# https://projecteuler.net/problem=75
#

from math import sqrt
from fractions import gcd

L = 1500000
limit = int(sqrt(L / 4))
length = (L + 1) * [0]

for n in range(1, limit + 1):	
	m = n + 1	
	while True:
		if gcd(m,n) == 1:
			a, b, c = m**2 - n**2, 2*m*n, m**2 + n**2
			s = a + b + c
			if s > L + 1: break
			k = 2
			while s < L + 1:
				length[s] += 1
				s = k*a + k*b + k*c
				k += 1 
		m += 2

print(sum(i for i in length if i == 1))