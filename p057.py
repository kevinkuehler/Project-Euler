from math import ceil, log10

on = od = 1  		# old num and denom
num, denom = 3, 2 	# current num and denom
cnt = 0
for i in range(1000):
	tn, td = num*2 + on, denom*2 +od
	on, od = num, denom
	num, denom = tn, td
	if ceil(log10(num)) > ceil(log10(denom)): cnt += 1

print(cnt)