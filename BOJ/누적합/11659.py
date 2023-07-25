# 11659 구간 합 구하기 4
# https://www.acmicpc.net/problem/11659
import sys
def input(): return sys.stdin.readline().rstrip()


N, M = map(int, input().split())
arr = list(map(int, input().split()))
tmp = [0, arr[0]]
answer = []

for i in range(1, N):
    tmp.append(arr[i]+tmp[i])

# print(tmp)

for _ in range(M):
    i, j = map(int, input().split())
    answer.append(tmp[j] - tmp[i-1])

for ans in answer:
    print(ans)
