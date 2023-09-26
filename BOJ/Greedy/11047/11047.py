# 11047 동전 0
# https://www.acmicpc.net/problem/11047
import sys
input = lambda : sys.stdin.readline().rstrip()

N,K = map(int,input().split())
coin_type = []
answer = 0

for i in range(N):
    coin_type.append(int(input()))

coin_type.sort(reverse=True) # 내림차순정렬

for i in range(N):
    if K == 0:
        break

    if K//coin_type[i]>0:
        answer += K//coin_type[i]
        K %= coin_type[i]

print(answer) # 출력