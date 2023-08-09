# 9205 맥주 마시면서 걸어가기
# https://www.acmicpc.net/problem/9205
import sys
from collections import deque
input = sys.stdin.readline


def solution(n, home, store, concert):
    que = deque([])
    que.append(home)
    visited = [False] * n

    while que:
        cur = que.popleft()

        if abs(cur[0]-concert[0]) + abs(cur[1]-concert[1]) <= 1000:
            print("happy")
            return

        for i in range(n):
            if not visited[i]:
                if abs(cur[0]-store[i][0]) + abs(cur[1]-store[i][1]) <= 1000:
                    visited[i] = True
                    que.append((store[i][0], store[i][1]))

    print("sad")
    return


T = int(input())

for _ in range(T):
    n = int(input())
    home = list(map(int, input().split()))
    store = []
    for _ in range(n):
        store.append(list(map(int, input().split())))
    concert = list(map(int, input().split()))

    solution(n, home, store, concert)
