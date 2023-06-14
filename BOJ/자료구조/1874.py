# 1874 스택 수열
# https://www.acmicpc.net/problem/1874
import sys
input = lambda : sys.stdin.readline().rstrip()

# 즉 스택에 넣어줬던 number를 inputCmm에서 부르면 안 됌
# 1. 스택이 비어있는지 아닌지 체크
# 2. 스택 상단이 cmm 보다 크다면 -> "-"
# 3. 작다면 "+""
# 4. 넣어주는 Number가 cmm보다 크면 No

n = int(input()) # 입력
stack = [] # 스택
inputCmm = []
answer = []

for _ in range(n):
    inputCmm.append(int(input()))

number = 1
flag = 0

for cmm in inputCmm:
    # number 보다 크거나 같다면 일단 push해줘야함
    while number <= cmm:
        stack.append(number)
        number += 1
        answer.append("+")
    
    # pop
    # stack의 상단이 cmm인지 확인해야함ㅁ
    if len(stack) > 0 and stack[-1] == cmm:
        answer.append("-")
        stack.pop() # 뺴줌
    
    else:
        print("NO")
        flag = 1 # 안된다는 걸 체크
        break

# 출력
if not flag:
    for a in answer:
        print(a)