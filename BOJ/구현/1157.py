# 1157 단어 공부
# https://www.acmicpc.net/problem/1157
import sys

input = sys.stdin.readline


def solution(word):
    alpOcc = [0 for _ in range(26)]

    for w in word.upper():
        alpOcc[ord(w)-65] += 1

    maxVal = max(alpOcc)
    cnt = 0
    for element in alpOcc:
        if maxVal == element:
            cnt += 1
    return '?' if cnt > 1 else chr(alpOcc.index(maxVal)+65)


word = input().rstrip()
print(solution(word))
