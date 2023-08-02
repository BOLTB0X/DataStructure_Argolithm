# 11659 구간 합 구하기 4
# https://www.acmicpc.net/problem/11659
import sys
def input(): return sys.stdin.readline().rstrip()


N, M = map(int, input().split())
arr = list(map(int, input().split()))
prefixsum = [0] * (N+1)

for i in range(1, N+1):
    prefixsum[i] = prefixsum[i-1] + arr[i-1]

for _ in range(M):
    a, b = map(int, input().split())
    print(prefixsum[b] - prefixsum[a-1])
