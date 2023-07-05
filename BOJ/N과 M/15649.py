# 15649 N과 M (1)
# https://www.acmicpc.net/problem/15649
import sys
from itertools import permutations
def input(): return sys.stdin.readline().rstrip()


N, M = map(int, input().split())

per = list(permutations([i for i in range(1, N+1)], M))
for p in per:
    print(*p)
