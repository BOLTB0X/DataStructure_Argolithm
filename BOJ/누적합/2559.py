# 2559 수열
# https://www.acmicpc.net/problem/2559
import sys
def input(): return sys.stdin.readline().rstrip()


N, K = map(int, input().split())
arr = list(map(int, input().split()))
partSum = sum(arr[:K])
answer = partSum

for i in range(len(arr)-K):
    partSum += arr[i+K] - arr[i]
    answer = max(answer, partSum)

print(answer)
# 1 2 3 4 5 6
# 1 3 6 10 15 21
# 1 (1+2) (3 + 3) (6 + 4) (10 + 5) (15 + 6)
