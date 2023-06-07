# 10828 스택
# https://www.acmicpc.net/problem/10828
import sys
input = lambda :sys.stdin.readline().rstrip()

T = int(input())
stack = []

for _ in range(T):
    comm = list(input().split())
    if comm[0] == "push":
        stack.append(int(comm[1]))
    elif comm[0] == "top":
        print(stack[-1] if len(stack)>0 else -1)
    elif comm[0] == "size":
        print(len(stack))
    elif comm[0] == "empty":
        print(1 if len(stack)==0 else 0)
    elif comm[0] == "pop":
        print(stack.pop() if len(stack)>0 else -1)