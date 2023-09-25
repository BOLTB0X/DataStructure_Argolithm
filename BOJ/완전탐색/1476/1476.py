# 1476 날짜 계산
# https://www.acmicpc.net/problem/1476
import sys
def input(): return sys.stdin.readline().rstrip()


E, S, M = map(int, input().split())
answer = 1

while True:
    if (answer - E) % 15 == 0 and (answer - S) % 28 == 0 and (answer - M) % 19 == 0:
        break
    answer += 1

print(answer)
