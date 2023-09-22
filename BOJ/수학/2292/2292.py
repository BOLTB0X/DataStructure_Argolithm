# 2292 벌집
# https://www.acmicpc.net/problem/2292
import sys
input = sys.stdin.readline

N = int(input())

answer = 1
number = 1

while N > number:
    number += (answer * 6)
    answer += 1

print(answer)
