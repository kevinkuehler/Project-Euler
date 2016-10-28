# Kevin Kuehler
# https://github.com/kevinkuehler/Project-Euler
#
# Project Euler Problem 63
# https://projecteuler.net/problem=63
#
from math import log10, ceil

def digit_pow(n):
	p = 1  
	while p <= ceil(p*log10(n)): 
		p += 1
	return p - 1

def main():
	print(sum(digit_pow(i) for i in range(2,10)) + 1)

if __name__ == '__main__':
	main()