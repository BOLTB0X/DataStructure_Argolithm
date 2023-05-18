#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'plusMinus' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def plusMinus(arr):
    # Write your code here
    answer = [0.0, 0.0, 0.0]
    
    for a in arr:
        if a > 0:
            answer[0] += (float(1)/float(len(arr)))
        elif a < 0 :
            answer[1] += (float(1)/float(len(arr)))
        else:
            answer[2] += (float(1)/float(len(arr)))
    
    for i in range(3):
        print(answer[i])

if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
