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
