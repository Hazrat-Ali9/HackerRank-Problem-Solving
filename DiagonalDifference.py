#!/bin/python3
# Diagonal Differences 
import math
import os
import random
import re
import sys

# Complete the diagonalDifference function below.
def diagonalDifference(arr):
    time =0
    sec=0
    length = len(arr[0])
    for count in range(length):
        time += arr[count][count]
        sec += arr[count][(length-count-1)]
    return abs(time-sec)
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = []

    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))

    result = diagonalDifference(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
    
    