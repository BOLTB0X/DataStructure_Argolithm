# 2164 카드2
# https://www.acmicpc.net/problem/2164
import sys
from collections import deque

input = sys.stdin.readline


def solution(n):
    cards = deque()

    for i in range(1, n+1):
        cards.append(i)

    while len(cards) > 1:
        cards.popleft()
        cards.append(cards.popleft())

    return cards.popleft()


n = int(input())

print(solution(n))
