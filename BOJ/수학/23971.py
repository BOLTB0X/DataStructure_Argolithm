# 23971 ZOAC 4
# https://www.acmicpc.net/problem/23971
import sys
import math
input = sys.stdin.readline

H, W, N, M = map(int, input().split())

print(math.ceil(H/(N+1))*math.ceil(W/(M+1)))
