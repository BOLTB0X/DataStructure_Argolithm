# 1932 정수 삼각형
# https://www.acmicpc.net/problem/1932
import sys
input = sys.stdin.readline


def solution(n, triangle):
    dp = [[0] * (i+1) for i in range(n)]

    dp[0][0] = triangle[0][0]

    for i in range(1, n):
        for j in range(i+1):
            if j == 0:
                dp[i][j] = triangle[i][j] + dp[i-1][j]
            elif j == i:
                dp[i][j] = triangle[i][j] + dp[i-1][j-1]
            else:
                dp[i][j] = triangle[i][j] + max(dp[i-1][j], dp[i-1][j-1])

    return max(dp[n-1])


n = int(input())
triangle = [list(map(int, input().split())) for _ in range(n)]

print(solution(n, triangle))
