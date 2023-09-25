# 7568 덩치
# https://www.acmicpc.net/problem/7568
import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
arr = []
for _ in range(N):
    arr.append(list(map(int,input().split())))
answer = []

for i in range(N):
    rank = 1
    for j in range(N):
        if i == j: # 자기 자신
            continue
        # 확실히 크다면
        if arr[i][0] < arr[j][0] and arr[i][1] < arr[j][1]:
            rank += 1

    answer.append(rank)

print(*answer)