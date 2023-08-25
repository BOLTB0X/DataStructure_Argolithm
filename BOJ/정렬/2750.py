# 2750 수 정렬하기
# https://www.acmicpc.net/problem/2750
import sys
input = sys.stdin.readline

N = int(input())
arr = [int(input()) for _ in range(N)]

# 정렬
arr.sort()

# 출력
for a in arr:
    print(a)
