# 1406 에디터
# https://www.acmicpc.net/problem/1406
import sys


def input():
    return sys.stdin.readline().rstrip()


leftStack = list(input())
rigthtStack = []

N = int(input())

for _ in range(N):
    cmm = input()  # 커서 기준으로 스택을 나눔
    if cmm == "L":  # 왼쪽 스택 이동
        if leftStack:
            rigthtStack.append(leftStack.pop())
    elif cmm == "D":  # 오른쪽 스택 이동
        if rigthtStack:
            leftStack.append(rigthtStack.pop())
    elif cmm == "B":
        if leftStack:
            leftStack.pop()
    else:
        leftStack.append(cmm[-1])  # 넣어줌

leftStack.extend(reversed(rigthtStack))  # 뒤집어서 넣어줌
print("".join(leftStack))
