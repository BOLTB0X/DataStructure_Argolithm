# 11723 집합
# https://www.acmicpc.net/problem/11723

import sys
def input(): return sys.stdin.readline().strip()


S = set()
M = int(input())

for _ in range(M):
    cmd = input().split()

    if len(cmd) == 1:
        if cmd[0] == "all":
            S = set([i for i in range(1, 21)])
        else:
            S = set()

        continue

    if cmd[0] == "add":
        S.add(int(cmd[1]))

    elif cmd[0] == "remove":
        S.discard(int(cmd[1]))

    elif cmd[0] == "check":
        print(1 if int(cmd[1]) in S else 0)

    elif cmd[0] == "toggle":
        if int(cmd[1]) in S:
            S.discard(int(cmd[1]))
        else:
            S.add(int(cmd[1]))
