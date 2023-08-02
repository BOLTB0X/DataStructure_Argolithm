# 2559 수열
# https://www.acmicpc.net/problem/2559
import sys
def input(): return sys.stdin.readline().rstrip()


N, K = map(int, input().split())
arr = list(map(int, input().split()))
prefixsum = [0] * (N+1)

for i in range(1, N+1):
    prefixsum[i] = prefixsum[i-1] + arr[i - 1]

answer = prefixsum[K]
for i in range(K, N+1):
    answer = max(answer, prefixsum[i] - prefixsum[i - K])

# print(prefixsum)
print(answer)
# 1 2 3 4 5 6
# 1 3 6 10 15 21
# 1 (1+2) (3 + 3) (6 + 4) (10 + 5) (15 + 6)
