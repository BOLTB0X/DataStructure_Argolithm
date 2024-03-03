# 9461 파도반 수열
# https://www.acmicpc.net/problem/9461
import sys

input = sys.stdin.readline

dp = [0] * 100
dp[0] = 1
dp[1] = 1
dp[2] = 1

for i in range(3, 100):
    dp[i] = dp[i-3]+dp[i-2]

t = int(input())

for _ in range(t):
    print(dp[int(input())-1])
