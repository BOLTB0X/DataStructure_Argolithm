# 1912 연속합
# https://www.acmicpc.net/problem/1912
import sys
input = sys.stdin.readline


def solution(n, numbers):
    dp = [0] * n
    dp[0] = numbers[0]

    for i in range(1, n):
        dp[i] = max(numbers[i]+dp[i-1], numbers[i])

    return max(dp)


n = int(input())
numbers = list(map(int, input().split()))

print(solution(n, numbers))
