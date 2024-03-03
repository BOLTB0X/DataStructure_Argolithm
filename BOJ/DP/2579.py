# 2579 계단 오르기
# https://www.acmicpc.net/problem/2579
import sys

input = sys.stdin.readline


def solution(n, steps):
    dp = [0 for _ in range(300)]

    dp[0] = steps[0]
    dp[1] = steps[0]+steps[1]
    dp[2] = max(steps[1]+steps[2], steps[0]+steps[2])

    for i in range(3, n):
        dp[i] = max(dp[i-3]+steps[i-1]+steps[i], dp[i-2]+steps[i])

    return dp[n-1]


n = int(input())
steps = [0 for _ in range(300)]

for i in range(n):
    steps[i] = int(input())


print(solution(n, steps))
