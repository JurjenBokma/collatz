#!/usr/bin/python3

from sys import argv

def collatz(n):
    return int(n / 2) if (n % 2 == 0) else 3 * n + 1

def ccount(n):
    count = 0
    while n != 1:
        n = collatz(n)
        count += 1
    return count

def spy_collatz(n):
    while True:
        print(n, end = " ")
        if n == 1:
            break
        n = collatz(n);

max_count = 0
max_seed = 1

argc = len(argv)
range_last = int(argv[2]) if argc > 2 else int(argv[1]) if argc > 1 else 1000
range_first = int(argv[1]) if argc > 2 else 1

for ix in range(range_first, range_last):
    count = ccount(ix)
    if count > max_count:
        max_count = count
        max_seed = ix

print("Max Collatz count in [", range_first, ", ", range_last, "] reaches ", max_count, " when sequence starts at ", max_seed, ":")
spy_collatz(max_seed);
print('\n')
