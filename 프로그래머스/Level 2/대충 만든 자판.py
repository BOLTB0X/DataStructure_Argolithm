# https://school.programmers.co.kr/learn/courses/30/lessons/160586
def makeDict(keymap):
    d = {}
    
    for keym in keymap:
        for i in range(len(keym)):
            # 딕셔너리에 없다면
            if keym[i] not in d:
                d[keym[i]] = i + 1
            else: # 비교 -> 최소를 해야하니
                d[keym[i]] = min(i + 1, d[keym[i]])
    
    return d

def solution(keymap, targets):
    answer = []
    d = makeDict(keymap) # 딕셔너리 만들기
    
    # 타겟 순회
    for target in targets:
        totCnt = 0 # 총 키 누른 횟수
        for t in target:
            if t in d: # 딕셔너리에 있면
                totCnt += d[t]
            else:
                totCnt = -1
                break # 단, 목표 문자열을 작성할 수 없을 때는 -1을 저장
        
  
        answer.append(totCnt)
            
    return answer