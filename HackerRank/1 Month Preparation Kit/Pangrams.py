#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'pangrams' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def check(arr):
    for a in arr:
        if a == 0:
            return False
    return True

def pangrams(s):
    newS = s.replace(" ", "").lower()
    alpCountList = [0 for _ in range(26)]
    
    for ns in newS:
        idx = ord(ns) - ord('a')
        alpCountList[idx] += 1
        
    if check(alpCountList):
        return "pangram"
    return "not pangram"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = pangrams(s)

    fptr.write(result + '\n')

    fptr.close()
