# 12789 도키도키 간식드리미
# https://www.acmicpc.net/problem/12789
import sys
from collections import deque

input = sys.stdin.readline


def solution(n, students):
    que = deque([s for s in students])
    stack = []
    currentWaiting = 1

    while que:
        currentStudent = que.popleft()
        if currentStudent == currentWaiting:
            currentWaiting += 1
        else:
            stack.append(currentStudent)

        while stack and stack[-1] == currentWaiting:
            stack.pop()
            currentWaiting += 1

    return "Nice" if not stack and currentWaiting > n else "Sad"


n = int(input())
students = list(map(int, input().split()))

print(solution(n, students))
