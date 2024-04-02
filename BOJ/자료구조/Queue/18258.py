# 18258 큐 2
# https://www.acmicpc.net/problem/18258
import sys
from collections import deque

input=lambda :sys.stdin.readline().rstrip()

T = int(input())
que = deque([])

for _ in range(T):
    comm = list(input().split())
    if comm[0] == "push":
        que.append(int(comm[1]))

    elif comm[0] == "front":
        print(que[0] if len(que) > 0 else -1)

    elif comm[0] == "back":
        print(que[-1] if len(que) > 0 else -1)

    elif comm[0] == "size":
        print(len(que))

    elif comm[0] == "empty":
        print(1 if len(que) == 0 else 0)

    elif comm[0] == "pop":
        print(que.popleft() if len(que) > 0 else -1)