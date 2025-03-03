#!/bin/python3

import math
import os
import random
import re
import sys


def pk(a):
    numbers = [0 for _ in range(100)]
    for i in a:
        numbers[i] += 1
    res = 0
    for i in range(1, 99):
        res = max(res, numbers[i] + numbers[i+1])
    return res
        
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    a = list(map(int, input().rstrip().split()))

    result = pk(a)

    fptr.write(str(result) + '\n')

    fptr.close()
