# 14929 귀찮아 (SIB)
# https://www.acmicpc.net/problem/14929
import sys
def input(): return sys.stdin.readline().rstrip()


n = int(input())
x = list(map(int, input().split()))
prefixsumX = [0] * (n+1)
answer = 0

for i in range(1, n):
    prefixsumX[i] = prefixsumX[i-1] + x[i-1]
    answer += (x[i])*prefixsumX[i]

print(answer)
