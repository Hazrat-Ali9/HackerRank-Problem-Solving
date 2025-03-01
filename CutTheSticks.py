#!/bin/python3

from collections import defaultdict

import math
import os
import random
import re
import sys



def cutTheSticks(arr):
    d = defaultdict(int)
    for a in arr:
        d[a] += 1
    d = sorted(list(d.items()))
    res = [len(arr)]
    for _, n in d[:-1]:
        res.append(res[-1] - n)
    return res

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = cutTheSticks(arr)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
