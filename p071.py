# Kevin Kuehler
# https://github.com/kevinkuehler/Project-Euler
#
# Project Euler Problem 71
# https://projecteuler.net/problem=71
#

#####################################################

# We know the neighbors a/b < c/d in a Farey sequence
# have a difference of 1/(bd). We are also given 
# c/d = 3/7, therefore 3/7-a/b = 1/(7b)
# => a = (3b-1)/7, such that a is an integer, and
# b <= L = 1,000,000 (largest denominator = set size)
def main():
    L, a = 1000000, -1

    for b in range(L, 2, -1):
        a = (3 * b - 1) / 7
        if int(a) == a: break
    print(int(a))

if __name__ == '__main__':
    main()


