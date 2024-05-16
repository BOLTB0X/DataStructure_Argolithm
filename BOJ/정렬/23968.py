# 23968 알고리즘 수업 - 버블 정렬 1
# https://www.acmicpc.net/problem/23968
import sys

input = sys.stdin.readline

# Bubble sort - upgrade


def bubbleSort(n, a):
    end = n-1
    while end > 0:
        lastSwap_idx = 0
        for i in range(end):
            if a[i] > a[i+1]:
                a[i], a[i+1] = a[i+1], a[i]
                lastSwap_idx = i
        end = lastSwap_idx
    return


def solution(n, k, a):
    res = [-1, -1]
    cnt = 0

    # Bubble sort - baisc
    for i in range(n-1, -1, -1):
        for j in range(i):
            if a[j] > a[j + 1]:
                a[j], a[j+1] = a[j+1], a[j]
                cnt += 1

                if cnt == k:
                    res = [a[j], a[j+1]]
                    break

    return res


n, k = map(int, input().split())
a = list(map(int, input().split()))
ret = solution(n, k, a)

if sum(ret) == -2:
    print(-1)
else:
    print(*ret)
