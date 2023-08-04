# 11441 합 구하기
# https://www.acmicpc.net/problem/11441
import sys
def input(): return sys.stdin.readline().rstrip()


N = int(input())
A = list(map(int, input().split()))
prefixsum = [0] * (N+1)

for i in range(1, N+1):
    prefixsum[i] = prefixsum[i-1] + A[i-1]

M = int(input())

for _ in range(M):
    s, e = map(int, input().split())
    print(prefixsum[e] - prefixsum[s-1])
