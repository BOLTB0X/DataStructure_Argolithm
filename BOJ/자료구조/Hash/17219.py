# 17219 비밀번호 찾기
# https://www.acmicpc.net/problem/17219
import sys
from collections import Counter

input = sys.stdin.readline


def solution(savedSites, findSites):
    counter = Counter()

    for site in savedSites:
        counter[site[0]] = site[1]

    return [counter[site] for site in findSites]


n, m = map(int, input().split())
savedSites = [list(input().split()) for _ in range(n)]
findSites = [input().rstrip() for _ in range(m)]

for r in solution(savedSites, findSites):
    print(r)
