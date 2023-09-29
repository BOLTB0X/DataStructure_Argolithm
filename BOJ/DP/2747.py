# 2747 피보나치 수
# https://www.acmicpc.net/problem/2747
import sys
input = sys.stdin.readline

def fibonacci(n):
    f = []
    for i in range(0,n+1):
        if i < 2:
            f.append(1)
        else:
            f.append(f[i-1]+f[i-2])
    return f[n-1]

print(fibonacci(int(input())))