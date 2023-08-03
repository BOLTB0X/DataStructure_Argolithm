# 1748 수 이어 쓰기 1
# https://www.acmicpc.net/problem/1748
import sys
def input(): return sys.stdin.readline().rstrip()


N = int(input())
answer = 0
i = 1

while i <= N:
    answer += (N-i+1)
    i *= 10
print(answer)
