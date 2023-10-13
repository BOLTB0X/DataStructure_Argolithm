# 14467 소가 길을 건너간 이유 1
# https://www.acmicpc.net/problem/14467
import sys

input = lambda : sys.stdin.readline().rstrip()

N = int(input())
answer = 0
cows = [-1 for _ in range(11)]

for _ in range(N):
    cowIdx, cur = map(int, input().split())
    flag = 0

    # 소가 움직임을 감지 했다면
    if cows[cowIdx] != -1 and cows[cowIdx] != cur:
        flag = 1
    
    if flag:
        answer += 1

    cows[cowIdx] = cur # 위치 체크

print(answer)