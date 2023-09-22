# 1316 그룹 단어 체커
# https://www.acmicpc.net/problem/1316
import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
answer = 0

for _ in range(N): # 총 횟수
    inputStr = input()
    
    tmp = ""
    flag = 1
    for s in inputStr: # 문자열 분석
        # 동일한 것이라면
        if len(tmp) > 0 and tmp[-1] == s:
            continue
        elif s in tmp: # 존재한다면
            flag = 0
            break # 탈출 
        tmp += s
    if flag: # 카운트 조건
        answer += 1
print(answer)