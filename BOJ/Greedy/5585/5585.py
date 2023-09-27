# 5585 거스름돈
# https://www.acmicpc.net/problem/5585
import sys
input = sys.stdin.readline

money = int(input())
answer = 0
moneyType = [500, 100, 50, 10, 5, 1]

cur = 1000-money

for m in moneyType:
    answer += cur // m
    cur %= m

print(answer)
