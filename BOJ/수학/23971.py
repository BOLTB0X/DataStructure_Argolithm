# 23971 ZOAC 4
# https://www.acmicpc.net/problem/23971
import sys
import math
input = sys.stdin.readline

H, W, N, M = map(int, input().split())

# 앉을 수 있는 자리 개수 = [ 길이 / ( 비우고 앉아야 하는 자리 개수 + 1) ] 을 반올림 한 값
print(math.ceil(H/(N+1))*math.ceil(W/(M+1)))
