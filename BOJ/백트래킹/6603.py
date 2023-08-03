# 6603 로또
# https://www.acmicpc.net/problem/6603
from itertools import combinations
import sys
def input(): return sys.stdin.readline().rstrip()


while True:
    k, *s = map(int, input().split())
    if k == 0:
        break
    C = list(combinations(s, 6))

    for c in C:
        print(*c)
    print()
