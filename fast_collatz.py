#!/usr/bin/python3

from sys import argv
import sys

# Since the module is not on the ${PYTHONPATH}, we specify the relative path to it.
sys.path.append('c++/collatz/')
import collatzpp


def spy_collatz(n):
    while True:
        print(n, end = " ")
        if n == 1:
            break
        n = collatzpp.collatz(n);


argc = len(argv)
range_last = int(argv[2]) if argc > 2 else int(argv[1]) if argc > 1 else 1000
range_first = int(argv[1]) if argc > 2 else 1

winner = collatzpp.find_winner(range_first, range_last + 1)

print("Max Collatz count in [{}, {}] reaches {} when sequence starts at {}:".format(range_first, range_last, collatzpp.collatz_count(winner), winner))
spy_collatz(winner);
print('\n')
