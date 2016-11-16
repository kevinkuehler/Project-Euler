# Kevin Kuehler
# https://github.com/kevinkuehler/Project-Euler
#
# Project Euler Problem 74
# https://projecteuler.net/problem=74
#

fact = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880] 
def digit_fact(n):
	sum = 0 
	while n > 0:
		sum += fact[n % 10]
		n //= 10 
	return sum

chains = (6 * fact[9] + 1) * [0] # 999,999 = 6 * 9!, max digit factorial

# factorians
chains[0] = chains[1] = chains[2] = chains[145] = chains[40585] = 1
# chains
chains[169] = chains[363601] = chains[1454] = 3
chains[871] = chains[872] = chains[45361] = chains[45362] = 2

# Utilizes memo table to store every new chain length
# so they don't have to be computed again. 
# Adds one to chain length until a digit factorial 
# with a known length occurs.
def chain_len(n):
	if chains[n] != 0:
		return chains[n] 
	chains[n] = 1 + chain_len(digit_fact(n))
	return chains[n]

L, MAX_CHAIN = 1000000, 60 
print(sum(1 for i in range(L) if chain_len(i) == MAX_CHAIN))


