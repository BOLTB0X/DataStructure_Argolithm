# 1620 나는야 포켓몬 마스터 이다솜
# https://www.acmicpc.net/problem/1620
import sys
from collections import Counter

input = sys.stdin.readline


def solution(n, m, pokeDex, targets):
    ret = []
    counter1, counter2 = Counter(), Counter()

    for i in range(n):
        counter1[pokeDex[i]] = str(i+1)
        counter2[str(i+1)] = pokeDex[i]

    for i in range(m):
        if targets[i] in counter2:
            ret.append(counter2[targets[i]])
        if targets[i] in counter1:
            ret.append(counter1[targets[i]])

    return ret


n, m = map(int, input().split())

pokeDex = [input().rstrip() for _ in range(n)]
targets = [input().rstrip() for _ in range(m)]

for r in solution(n, m, pokeDex, targets):
    print(r)
