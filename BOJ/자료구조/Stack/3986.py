# 3986 좋은 단어
# https://www.acmicpc.net/problem/3986
import sys

input = sys.stdin.readline


def solution(n, words):
    res = 0

    for word in words:
        stack = []

        for w in word:
            if stack and stack[-1] == w:
                stack.pop()
            else:
                stack.append(w)

        if not stack:
            res += 1

    return res


n = int(input())
words = [input().rstrip() for _ in range(n)]

print(solution(n, words))
