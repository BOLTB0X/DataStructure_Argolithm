# https://school.programmers.co.kr/learn/courses/30/lessons/140108
def solution(s):
    answer = 0
    
    while len(s) > 1:
        x = s[0] # 첫 글자를 읽습
        firstCnt = 1
        otherCnt = 0
        splitIdx = -1
        flag = 0 # 끝까지 갔나 체크
        
        for i in range(1,len(s)):
            if s[i] == x:
                firstCnt += 1
            else:
                otherCnt += 1
            
            if firstCnt == otherCnt: # 처음으로 두 횟수가 같아지는 순간 멈추고,
                splitIdx = i+1
                break
            if len(s)-1 == i:
                flag = 1
                
        # 분리가 안된다면
        if flag == 1:
            break # 만약 두 횟수가 다른 상태에서 더 이상 읽을 글자가 없다면, 역시 지금까지 읽은 문자열을 분리하고, 종료
            
        answer += 1 # 분해한 문자열의 개수 카운트
        s = s[splitIdx:] # 분리한 문자열을 빼고 남은 부분
    
    if len(s) > 0:
        answer += 1
    return answer