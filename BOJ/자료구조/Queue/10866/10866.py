# 10866 덱
# https://www.acmicpc.net/problem/10866
import sys
from collections import deque

input = lambda :sys.stdin.readline().rstrip()

T = int(input())
dq = deque([])

for _ in range(T):
    comm = list(input().split())
    if comm[0] == "push_back":
        dq.append(int(comm[1]))

    elif comm[0] == "push_front":
        dq.appendleft(int(comm[1]))

    elif comm[0] == "pop_front":
        print(dq.popleft() if len(dq) > 0 else -1)
    
    elif comm[0] == "pop_back":
        print(dq.pop() if len(dq) > 0 else -1)

    elif comm[0] == "front":
        print(dq[0] if len(dq) > 0 else -1)
    
    elif comm[0] == "back":
        print(dq[-1] if len(dq) > 0 else -1)
    
    elif comm[0] == "size":
        print(len(dq))

    elif comm[0] == "empty":
        print(1 if len(dq) == 0 else 0)

