def reverse(n):
	r = 0
	while n:
		r = r*10 + n%10
		n //= 10
	return r

def lychrel(x):
	x += reverse(x) # for palindromic lychrels
	for i in range(49):
		xr = reverse(x)
		if x == xr: return 0
		x += xr
	return 1

print(sum(lychrel(i) for i in range(10,10000)))
