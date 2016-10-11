import math

f1 = f2 = f3 = 1
index = 2
while math.floor(math.log10(f3)) != 999:
	f3 = f1 + f2
	f1 = f2
	f2 = f3
	index+= 1

print(index)