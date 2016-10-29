# Kevin Kuehler
# https://github.com/kevinkuehler/Project-Euler
#
# Project Euler Problem 66
# https://projecteuler.net/problem=66
#

from math import sqrt, floor

# pass: numerator and denominator of nth convergent,
#		n-1 continued fraction sequence
# ret : numerator and denominator of nth convergent
#
# Multiplies next number in the sequence
# by denominator for common denoms and flips
# numerator and denominator since they are divided by 1.
# B.C. adds last number in sequence to fraction
def convergent(denom, seq, num=1):
	if len(seq) == 1:
		return int(seq.pop()*denom + num), int(denom)
	return convergent(seq.pop()*denom + num, seq, denom)

# Generates the continued fraction sequence 
# and tries the ratio (x/y) of each unique  
# convergent in the eqn x^2 - Dy^2 = 1
# until the eqn is satisfied. 
# Returns x from the correct (x,y) set.
def pell_minimal(s):
	a0 = floor(sqrt(s))
	if a0*a0 == s: return -1
	m, d, a, = 0, 1, a0

	seq = [a0]
	
	while True:
		m = d*a - m
		d = (s-m**2) / d
		a = floor((a0+m) / d)
		xy = convergent(a, seq[:])
		if xy[0]**2 - s*xy[1]**2 == 1: return xy[0]
		seq.append(a)	

# Prints the value D that produced the  
# largest x in Pell's Eqn for D <= 1000.
def main():
	print(max((pell_minimal(i), i) for i in range(2,1000))[1])

if __name__ == '__main__':
	main()	