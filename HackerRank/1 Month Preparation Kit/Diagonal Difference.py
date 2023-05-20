#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'diagonalDifference' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#

def diagonalDifference(arr):
    leftTOright = 0
    rightToleft = 0
    
    # (1,1) (2,2) (3,3)
    # (1,3) (2, 2) (3,1)
    for i in range(len(arr)):
        leftTOright += arr[i][i]
        rightToleft += arr[i][len(arr)-1-i]
    
    return abs(leftTOright - rightToleft)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = []

    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))

    result = diagonalDifference(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
