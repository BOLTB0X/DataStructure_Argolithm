# 2839 설탕 배달
# https://www.acmicpc.net/problem/2839
import sys
input = sys.stdin.readline

n = int(input()) #설탕 무게입력
ans = 0
while True:
    if n%5 == 0:
        ans+=(n//5)
        print(ans)
        break
    n -= 3
    ans += 1
    if n<0:
        print(-1)
        break