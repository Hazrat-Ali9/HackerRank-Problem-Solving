#!/bin/python3

from collections import defaultdict

import math
import os
import random
import re
import sys

#
# Complete the 'organizingContainers' function below.
#
# The function is expected to return a STRING.
# The function accepts 2D_INTEGER_ARRAY container as parameter.
#

def organizingContainers(container):
    n = len(container)
    ball = [0 for _ in range(n)]
    mm = defaultdict(int)
    for c in container:
        mm[sum(c)] += 1
        for i, bowl in enumerate(c):
            ball[i] += bowl
    for bowl in ball:
        if bowl in mm and mm[bowl] > 0:
            mm[bowl] -= 1
        else:
            return "Impossible"
    return "Possible"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        n = int(input().strip())

        container = []

        for _ in range(n):
            container.append(list(map(int, input().rstrip().split())))

        result = organizingContainers(container)

        fptr.write(result + '\n')

    fptr.close()
