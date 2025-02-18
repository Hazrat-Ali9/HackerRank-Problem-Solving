#!/bin/python3
# The Conversation 
import math
import os
import random
import re
import sys


def timeConversion(s):
    is_time = (s[:2] == "12")
    is_pm = (s[-2:] == "PM")
    if is_pm:
        if is_time:
            return s[:-2]
        else:
            return str(int(s[:2]) + 12) + s[2:-2]
    else:
        if is_time:
            return "00" + s[2:-2]
        else:
            return s[:-2]
            
            
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    fptr.write(result + '\n')

    fptr.close()
