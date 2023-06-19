# 2022 KAKAO BLIND RECRUITMENT 신고 결과 받기
def solution(id_list, report, k):
    answer = []
    idDict = {} # 누가 누구를
    idTotDict = {} # 총 신고 당한 것 체크 
    checkDict = {} # 최종적으로 정지당한 아이디 체크
    
    for id in id_list: # 생성
        idTotDict[id] = 0 
        checkDict[id] = []
    
    for r in report:
        a,b = r.split() # a는 신고자 b는 신고 당한사람
        if not a in idDict:
            idDict[a] = [b]
        else:
            if b in idDict[a]: # 중복 신고 X
                continue
            idDict[a].append(b)
    
    #print(idTotDict)
    #print(idDict)
    
    # 신고 당한 넘들을 체크 해줌
    for (key, value) in idDict.items():
        for v in value:
            idTotDict[v] += 1
    #print(idTotDict)
    
    # 신고한 사람이 보낸 아이디 체크
    for (key, value) in idDict.items():
        for v in value:
            if idTotDict[v] >= k:
                checkDict[key].append(v)
    
    # 정답에 넣어줌
    for (key, value) in checkDict.items():
        if len(value) == 0:
            answer.append(0)
        else:
            answer.append(len(value))
    return answer