# Kevin Kuehler
# https://github.com/kevinkuehler/Project-Euler
#
# Project Euler Problem 62
# https://projecteuler.net/problem=62
#
from collections import defaultdict

# orders a number n from largest digit to smallest
def max_perm(n):
	list =  sorted([int(i) for i in str(n)], reverse=True)
	return int(''.join(str(i) for i in list))

def main():
	cubes = defaultdict(int)
	first = defaultdict(int)
	i = 1
	while True:
		x = max_perm(i**3)
		if cubes[x] == 4: 
			break
		elif not cubes[x]: 
			first[x] = i
		cubes[x] += 1
		i += 1
	print(first[x]**3)

if __name__ == '__main__':
	main()