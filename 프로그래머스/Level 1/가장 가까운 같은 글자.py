# https://school.programmers.co.kr/learn/courses/30/lessons/142086?language=python3
def solution(s):
    answer = []
    check = {}
    
    for i in range(len(s)):
        if not s[i] in check: # 처음 등장
            answer.append(-1)
        else: # 있다면
            answer.append(i-check[s[i]])
        check[s[i]] = i # 교체
    return answer