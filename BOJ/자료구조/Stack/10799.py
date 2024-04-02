# 10799 쇠막대기
# https://www.acmicpc.net/problem/10799

stick = input()
stack = []
answer = 0

for i in range(len(stick)):
    if stick[i] == '(':
        stack.append(stick[i])
    else:
        if len(stack) > 0 and stick[i-1] == '(':
            stack.pop()
            answer += len(stack)
        else:
            stack.pop()
            answer += 1
print(answer)
