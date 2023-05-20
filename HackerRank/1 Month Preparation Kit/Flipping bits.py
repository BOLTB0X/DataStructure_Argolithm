#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'flippingBits' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts LONG_INTEGER n as parameter.
#

def getBinary(n, lists):
    a = n // 2
    b = n % 2
    lists.append(b)
    
    if a == 0:
        return lists
    else:
        return getBinary(a, lists)

def flippingBits(n):
    # Write your code here
    binNumber = getBinary(n, [])
    
    while len(binNumber) < 32 :
        binNumber.append(0)
    
    for i in range(32):
        if binNumber[i] == 0:
            binNumber[i] = 1
        else:
            binNumber[i] = 0
    
    return int("".join([str(_) for _ in reversed(binNumber)]), 2)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        n = int(input().strip())

        result = flippingBits(n)

        fptr.write(str(result) + '\n')

    fptr.close()
