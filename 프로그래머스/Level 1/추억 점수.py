# https://school.programmers.co.kr/learn/courses/30/lessons/176963?language=python3
def solution(name, yearning, photo):
    answer = []
    nameDict = {}
    
    for pp in photo:
        nameDict = {} # 임시 딕셔너리
        for p in pp:
            if not p in nameDict:
                nameDict[p] = 1
            else:
                nameDict[p] += 1
        
        score = 0
        for key, value in nameDict.items():
            for i in range(len(name)):
                if name[i] == key:
                    score += value * yearning[i]
                    break
        answer.append(score)
    return answer