# 11399 ATM
# https://www.acmicpc.net/problem/11399
import sys
input = sys.stdin.readline

n = int(input())
P = list(map(int,input().split()))

P.sort()
tot=0
answer = 0

for i in range(n):
    tot+=P[i]
    answer += tot

print(answer)