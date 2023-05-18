#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'timeConversion' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def timeConversion(s):
    # Write your code here
    splitedS = s.split(':')
    if (splitedS[2][2:] == "PM") and (splitedS[0] < "12"):
        splitedS[0] = str(int(splitedS[0])+12)
    
    elif splitedS[2][2:] == "AM":
        if splitedS[0] == "12":
            splitedS[0] = "00"
    
    return (splitedS[0] + ":" + splitedS[1] + ":" + splitedS[2][:2])
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    fptr.write(result + '\n')

    fptr.close()
