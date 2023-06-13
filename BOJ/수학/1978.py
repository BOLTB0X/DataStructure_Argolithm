# 1978 소수 찾기
# https://www.acmicpc.net/problem/1978
import sys
import math
input =  lambda: sys.stdin.readline().rstrip()

# 소수 판별
def isPrime(num):
    if num == 0 or num == 1:
        return False
    
    for i in range(2, int(math.sqrt(num))+1):
        if not num % i:
            return False

    return True

n = int(input())
numbers = list(map(int, input().split()))
answer = 0

for num in numbers:
    if isPrime(num):
        answer += 1
print(answer)
