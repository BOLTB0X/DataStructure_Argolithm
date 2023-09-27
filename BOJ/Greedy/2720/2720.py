# 2720 세탁소 사장 동혁
# https://www.acmicpc.net/problem/2720
import sys
input = sys.stdin.readline

Quarter = [25, 10, 5, 1]

T = int(input())

for _ in range(T):
    C = int(input())
    answer = [0]*4
    for i in range(4):
        answer[i] = C//Quarter[i]
        Quarter %= C
    print(*answer)