#!/bin/python3

import math
import os
import random
import re
import sys



def getTotalX(a, b):
    res = 0
    for i in range(max(a), min(b) + 1):
        res += (all([i % aa == 0 for aa in a]) and all([bb % i == 0 for bb in b]))
    return res

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    arr = list(map(int, input().rstrip().split()))

    brr = list(map(int, input().rstrip().split()))

    total = getTotalX(arr, brr)

    fptr.write(str(total) + '\n')

    fptr.close()
