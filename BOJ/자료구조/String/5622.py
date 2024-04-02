# 5622 다이얼
# https://www.acmicpc.net/problem/5622
import sys

input = sys.stdin.readline


def solution(s):
    ret = 0
    dial = ['ABC', 'DEF', 'GHI', 'JKL', 'MNO', 'PQRS', 'TUV', 'WXYZ']

    for i in range(len(s)):
        for d in dial:
            if s[i] in d:
                ret += (dial.index(d)+3)

    return ret


s = input().rstrip()

print(solution(s))
