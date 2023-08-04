# 2075 N번째 큰수
# https://www.acmicpc.net/problem/2075
import sys
def input(): return sys.stdin.readline().rstrip()


N = int(input())
arr = []

for i in range(N):
    arr += list(map(int, input().split()))
    arr = sorted(arr, reverse=True)[:N]
print(arr[N-1])
