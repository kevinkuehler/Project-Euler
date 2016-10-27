# Kevin Kuehler
# https://github.com/kevinkuehler/Project-Euler
#
# Project Euler Problem 61
# https://projecteuler.net/problem=61
#
from bisect import bisect_left

def binary_search(a, x, lo=0, hi=None):   
    hi = hi if hi is not None else len(a)   
    pos = bisect_left(a,x,lo,hi)         
    return (pos if pos != hi and a[pos] == x else -1) 

# Given some side s (i.e. 3 is triangular, 4 is square, etc)
# we can generate the nth number of that sequence. 
def figurate(s, n):
	return n*((s - 2) * n - (s - 4)) // 2

figurates = [[figurate(j+3,i) for i in range(19,141)] for j in range(6)]

# Receives an octagonal number
# Recursively checks all cycles that are figurates, 
# and stores each cycle with it's figurate type as tuple in list.
# Used in B.C. to determine if all numbers are different figurates. 
def find_cycle(n, group, list, index):
	if n < 1000: return 0 
	list[index] = (group, n)
	
	if index == 5: 
		if list[5][1] % 100 != list[0][1] // 100: return 0 # check that last cycles first
		for x in range(6):
			for z in range(x+1,6):
				if list[x][0] == list[z][0]: return 0	
		return sum(x for _, x in list)

	next = (n % 100)*100
	if next < 10: return 0 # avoid useless compares
	val = 0 # for recursion retrn
	for i in range(10,100):
		t = next + i
		for j in range(5):
			if binary_search(figurates[j],t) != -1:
				val = find_cycle(t, j+3, list, index+1)
				if val != 0: return val # found
	return val

# Generates cycles using the octagonal numbers b/t 1 and 10 thousand. 
def Main():
	found = [(None,None)]*6 
	result = 0
	for i in range(40):
		result = find_cycle(figurates[5][i], 8, found, 0)
		if result != 0: break
	print(result)

if __name__ == '__main__':
	Main()
