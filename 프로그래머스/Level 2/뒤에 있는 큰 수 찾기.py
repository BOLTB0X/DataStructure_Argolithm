# https://school.programmers.co.kr/learn/courses/30/lessons/154539
# 시간초과
def solution(numbers):
    answer = []
    
    for i in range(len(numbers)-1):
        for j in range(i+1, len(numbers)):
            if numbers[i] < numbers[j]:
                answer.append(numbers[j])
                break
        else:
            answer.append(-1)
    answer.append(-1)
    return answer

# 정답
def solution(numbers):
    answer = [-1] * len(numbers)
    stack = [] # 스택 이용
    
    for i in range(len(numbers)):
        while stack and numbers[stack[-1]] < numbers[i]:
            answer[stack.pop()] = numbers[i]
        stack.append(i)
        
    return answer