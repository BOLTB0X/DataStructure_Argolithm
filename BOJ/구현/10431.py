# 10431 줄세우기
# https://www.acmicpc.net/problem/10431
import sys
input = sys.stdin.readline


def solution(children):
    answer = 0

    for i in range(1, 21):
        for j in range(i+1, 21):
            if children[i] > children[j]:
                children[i], children[j] = children[j], children[i]
                answer += 1

    return answer


T = int(input())

for _ in range(T):
    arr = list(map(int, input().split()))

    print(arr[0], solution(arr))
