# Kevin Kuehler
# https://github.com/kevinkuehler/Project-Euler
#
# Project Euler Problem 72
# https://projecteuler.net/problem=72
#

def coprime(len):
	phi = [1] * (len+1)

	for i in range(2,len+1):
		if phi[i] == 1:
			for j in range(i+i, len+1, i):
				phi[j] *= 1 - 1 / i
	return phi

def main():
	L = 1000000
	phi = coprime(L + 1)

	# use euler's totient function if we have a phi value
	# not equal to 1 -- 1 means prime.
	print(sum([i - 1 if phi[i] == 1 
		else round(i * phi[i]) for i in range(2, L + 1)]))

if __name__ == '__main__':
	main()
