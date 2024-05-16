# 10431 줄세우기
# https://www.acmicpc.net/problem/10431
import sys

input = sys.stdin.readline


def solution(students):
    res = 0

    for i in range(20):
        for j in range(i+1, 20):
            if students[i] > students[j]:
                res += 1

    return res


t = int(input())

for _ in range(t):
    students = list(map(int, input().split()))

    print(students[0], solution(students[1:]))
