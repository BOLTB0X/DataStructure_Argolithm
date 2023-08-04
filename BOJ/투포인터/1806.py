# 1806 부분합
# https://www.acmicpc.net/problem/1806
import sys
def input(): return sys.stdin.readline().rstrip()


N, S = map(int, input().split())
A = list(map(int, input().split()))
answer = 100001
partSum = A[0]
s, e = 0, 0

while e < N:
    if partSum >= S:
        answer = min(answer, e-s+1)
        # print(s, e)
        partSum -= A[s]
        s += 1

    elif partSum < S:
        e += 1
        if e == N:
            break
        partSum += A[e]

print(answer if answer != 100001 else 0)
