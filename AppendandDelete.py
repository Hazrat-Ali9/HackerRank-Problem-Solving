import math
import os
import random
import re
import sys

#
# Complete the 'appendAndDelete' function below.
#
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. STRING s
#  2. STRING t
#  3. INTEGER k
#

def appendAndDelete(a, b, c):
    i = 0
    while i < min(len(a), len(b)) and a[i] == b[i]:
        i += 1
    x = len(a) + len(b) - (2 * i)
    if x <= c and ((c - x) % 2 == 0 or (len(a) + len(b)) <= c):
        return "Yes"
    else:
        return "No"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    t = input()

    k = int(input().strip())

    result = appendAndDelete(s, t, k)

    fptr.write(result + '\n')

    fptr.close()

