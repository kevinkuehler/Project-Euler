# Kevin Kuehler
# https://github.com/kevinkuehler/Project-Euler
#
# Project Euler Problem 69
# https://projecteuler.net/problem=69
#

def coprime_max(len):
	phi = [1]*(len+1)

	for i in range(2,len+1):
		if phi[i] == 1:
			for j in range(i+i, len+1, i):
				phi[j] *= i / (i - 1)
	return phi

def main():
	L = 1000000
	phi = coprime_max(L)

	print(max((phi[i], i) for i in range(2, L))[1])

if __name__ == '__main__':
	main()