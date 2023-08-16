# 9655 돌 게임
# https://www.acmicpc.net/problem/9655
import sys

input = sys.stdin.readline

N = int(input())
dp = [0] * 1001

dp[1], dp[2] = 1, 2

for i in range(3, 1001):
    dp[i] = min(dp[i-1]+1, dp[i-3]+1)

if not dp[N] % 2:
    print("CY")
else:
    print("SK")
