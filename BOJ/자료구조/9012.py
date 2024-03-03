# 9012 괄호
# https://www.acmicpc.net/problem/9012

def solution(parentheses):
    stack = []

    for p in parentheses:
        if p == '(':
            stack.append(0)
        else:
            if not len(stack):
                return 'NO'
            stack.pop()

    return 'YES' if not len(stack) else 'NO'


n = int(input())

for _ in range(n):
    print(solution(input()))
