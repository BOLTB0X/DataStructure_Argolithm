# 11053 가장 긴 증가하는 부분 수열
# https://www.acmicpc.net/problem/11053

import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
A = list(map(int,input().split())) # 수열

# LIS(Longest Increasing Subsequence)
dp = [1 for i in range(N+1)] # 길이를 넣어주는 리스트

for i in range(N):
    for j in range(i):
        if A[i] > A[j]: # 길이를 업데이트
            dp[i] = max(dp[i], dp[j] + 1)

print(max(dp)) # 출력