# 24416 알고리즘 수업 - 피보나치 수 1
# https://www.acmicpc.net/problem/24416
import sys

input = sys.stdin.readline


def fib(n):
    a, b = 1, 1

    for _ in range(3, n+1):
        a, b = b, a+b

    return b


def fibonacci(n):
    return n-2


def solution(n):
    return [fib(n), fibonacci(n)]


n = int(input())
print(*solution(n))
