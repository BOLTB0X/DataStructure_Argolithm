# 2753 윤년
# https://www.acmicpc.net/problem/2753
import sys

input = lambda : sys.stdin.readline().rstrip()

N = int(input())

if N % 4 == 0 and N % 100 !=0 or N % 400 ==0:
    print(1)
else:
    print(0)