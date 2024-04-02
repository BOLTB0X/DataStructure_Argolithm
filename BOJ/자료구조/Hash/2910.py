# 2910 빈도 정렬
# https://www.acmicpc.net/problem/2910
import sys

input = sys.stdin.readline


def solution(n, c, seq):
    res = []
    dic = {}

    for i in range(n):
        if seq[i] in dic:
            dic[seq[i]] += 1
        else:
            dic[seq[i]] = 1

    sortedArr = sorted(dic.items(), key=lambda x: -x[1])

    for element in sortedArr:
        res.extend([element[0]]*element[1])

    return res


n, c = map(int, input().split())
seq = list(map(int, input().split()))

print(*solution(n, c, seq))
