# Kevin Kuehler
# https://github.com/kevinkuehler/Project-Euler
#
# Project Euler Problem 65
# https://projecteuler.net/problem=65
#


# pass: num, denom of nth convergent, n-1
# returns: num of nth convergent for e
#
# Uses the fact that every third sequence 
# of e is an even number 2k, where k = s/3.
# We add this number to our fraction and
# swap num and denom since they are over one,
# In B.C. the fraction is added to 2.
def e_convergent(num, denom, seq):
	if seq == 1:
		return int(2*denom + num)
	next = 2*seq/3 if seq % 3 == 0 else 1
	return e_convergent(denom, next*denom + num, seq - 1)

# Sums digits of the 100th convergent
def main():
	print(sum(int(i) for i in str(e_convergent(1,1,99))))

if __name__ == '__main__':
	main()
