# 9375 패션왕 신해빈
# https://www.acmicpc.net/problem/9375
import sys
from collections import Counter
input = sys.stdin.readline


def solution(n, clothes):
    ret = 1
    clothesCounter = Counter(clothes)

    for key in clothesCounter.keys():
        ret *= (clothesCounter[key]+1)

    return ret-1  # 공집합 제외


t = int(input())

for _ in range(t):
    n = int(input())
    clothes = [input().split()[1] for _ in range(n)]
    print(solution(n, clothes))
