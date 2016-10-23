from math import sqrt, ceil

def is_prime(n): 
    if n < 2 or n % 2 == 0: return False
    for i in range(3, ceil(sqrt(n))+1, 2):
        if n % i == 0: return False
    return True

n,i,side_width,primes = 1,1,2,0
while True :
	for j in range(3):
		n+=side_width
		if is_prime(n): primes += 1
	if primes / (4*i+1) < 0.10: break
	n += side_width # skipping sq diagonal
	side_width += 2
	i += 1

print(side_width+1)


