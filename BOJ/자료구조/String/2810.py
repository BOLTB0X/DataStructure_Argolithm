# 2810 컵홀더
# https://www.acmicpc.net/problem/2810
import sys

input = sys.stdin.readline


def solution(n, sits):
    sCount = sits.count('S')
    llCount = sits.count('LL')

    return sCount + llCount + 1 if llCount > 0 else n


n = int(input())
sits = input().rstrip()

print(solution(n, sits))
