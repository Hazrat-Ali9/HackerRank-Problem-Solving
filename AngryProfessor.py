#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the angryProfessor function below.

# Simple Function

def angryProfessor(k, a):
    count=0
    for i in range(len(a)):
        if(a[i]<=0):
            count+=1
    if(count>=k):
        return "NO"
    return "YES"
    
# Hacker Program 
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        nk = input().split()

        n = int(nk[0])

        k = int(nk[1])

        a = list(map(int, input().rstrip().split()))

        result = angryProfessor(k, a)

        fptr.write(result + '\n')

    fptr.close()
    # Angry Professor 
