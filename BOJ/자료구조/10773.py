# 10773 제로
# https://www.acmicpc.net/problem/10773

def solution(k, inputList):
    stack = []

    for i in range(k):
        if inputList[i]:
            stack.append(inputList[i])

        elif not inputList[i] and len(stack) > 0:
            stack.pop()

    return sum(stack)


k = int(input())
inputList = [int(input()) for _ in range(k)]

print(solution(k, inputList))
