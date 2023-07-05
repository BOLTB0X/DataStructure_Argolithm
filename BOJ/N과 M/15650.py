# 15650 N과 M (2)
# https://www.acmicpc.net/problem/15650
import sys
from itertools import combinations
def input(): return sys.stdin.readline().rstrip()


N, M = map(int, input().split())
combi = combinations([i for i in range(1, N+1)], M)

for c in combi:
    print(*c)
