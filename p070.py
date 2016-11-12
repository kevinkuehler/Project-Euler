# Kevin Kuehler
# https://github.com/kevinkuehler/Project-Euler
#
# Project Euler Problem 70
# https://projecteuler.net/problem=70
#

from math import floor, sqrt

def sieve_erato(len):
	primes = [True]*(len+1)
	primes[0] = primes[1] = False
	
	for i in range(2,floor(sqrt(len+1))):
		if primes[i]:
			for j in range(i*i, len+1, i):
				primes[j] = False
	return primes

def is_perm(h, k):
	digits = [0] * 10 
	while h > 0 and k > 0:
		digits[h % 10] += 1
		digits[k % 10] -= 1 
		h //= 10
		k //= 10
	return h == k and all(d == 0 for d in digits)

def main():
	sieve = sieve_erato(10000)
	l = 10000000
	x = (l,-1)

	for i in range(1009, 4000, 2):
		if sieve[i]:
			for j in range(i + 2, 4000, 2):
				if i * j > l: break
				if sieve[j]:
					n, n_totient = i * j, (i - 1) * (j - 1)
					if is_perm(n, n_totient):
						x = min(x, (n / n_totient, n))		
	print(x[1])

if __name__ == '__main__':
	main()


