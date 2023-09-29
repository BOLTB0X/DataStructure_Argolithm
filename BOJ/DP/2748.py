# 2748 피보나치 수 2
# https://www.acmicpc.net/problem/2748

def fib(n):
    a,b=0,1
    for i in range(n):
        a,b=b,a+b
    return a

print(fib(int(input())))