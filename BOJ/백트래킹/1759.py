# 1759 암호 만들기
# https://www.acmicpc.net/problem/1759
import sys
from itertools import combinations
def input(): return sys.stdin.readline().rstrip()


L, C = map(int, input().split())
arr = list(input().split())
arr.sort()

for com in combinations(arr, L):
    mCnt, jCnt = 0, 0
    for c in com:
        if c in ["a", "e", "i", "o", "u"]:
            mCnt += 1
        else:
            jCnt += 1

    if mCnt >= 1 and jCnt >= 2:
        print("".join(com))
