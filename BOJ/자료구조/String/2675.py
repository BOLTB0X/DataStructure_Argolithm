# 2675 문자열 반복
# https://www.acmicpc.net/problem/2675
import sys

input = sys.stdin.readline


def solution(r, s):
    ret = ''

    for ch in s:
        ret += (ch*r)

    return ret


t = int(input())

for _ in range(t):
    r, s = input().split()

    print(solution(int(r), s))
