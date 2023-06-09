# 9012 괄호
# https://www.acmicpc.net/problem/9012
import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())

for _ in range(N): # 시뮬레이션 시작
    parenth = input()
    stack = [] # 스택
    
    for p in parenth:
        if p == "(":
            stack.append(0)
        else: # 닫음을 만났을 떄
            if stack: # 원소가 있다면
                stack.pop()
            else:
                print("NO")
                break
    else:
        if not stack:
            print("YES")
        else:
            print("NO")
