# 8979 올림픽
# https://www.acmicpc.net/problem/8979
import sys
input = sys.stdin.readline

N, K = map(int, input().split())

medalArr = [list(map(int, input().split())) for _ in range(N)]

medalArr.sort(key=lambda x: (x[1], x[2], x[3]), reverse=True)

idx = [medalArr[i][0] for i in range(N)].index(K)

for i in range(N):
    if medalArr[idx][1:] == medalArr[i][1:]:
        print(i+1)
        break
