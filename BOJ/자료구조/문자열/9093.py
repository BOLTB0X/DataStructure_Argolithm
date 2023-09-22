# 9093 단어 뒤집기
# https://www.acmicpc.net/problem/9093
import sys
input = lambda : sys.stdin.readline().rstrip()

T = int(input())

for _ in range(T):
    # 입력
    words=list(input().split())
    
    for word in words:
        print(word[::-1], end = " ")
    print()