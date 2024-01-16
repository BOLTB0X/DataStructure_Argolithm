# https://school.programmers.co.kr/learn/courses/30/lessons/258712
def solution(friends, gifts):
    answer = 0
    getset_dict = { friend: { fr: 0 if fr != friend else -1 for fr in friends } for friend in friends }
    getDict = { friend:0 for friend in friends }
    setDict = { friend:0 for friend in friends }
    nextInfo = { friend:0 for friend in friends }
    
    for gift in gifts:
        getter, setter = gift.split()
        getset_dict[getter][setter] += 1
        getDict[getter] += 1
        setDict[setter] += 1
    
    # print(getset_dict)
    # print(getDict)
    # print(setDict)
    
    for k1,v1 in getset_dict.items():
        for (k2,v2) in v1.items():
            if v2 == -1 or k1 == k2: continue # 자기 자신
            #print(k2, v2)
            
            #  이번 달까지 두 사람 사이에 더 많은 선물을 준 사람이
            if v2 > getset_dict[k2][k1]:
                #print(k1, k2)
                nextInfo[k1] += 1
                
            # 두 사람이 선물을 주고받은 기록이 하나도 없거나 주고받은 수가 같다면
            elif (v2 == 0 and getset_dict[k2][k1] == 0) or (v2 == getset_dict[k2][k1]):
                score1 = getDict[k1] - setDict[k1]
                score2 = getDict[k2] - setDict[k2]

                if score1 > score2: 
                    nextInfo[k1] += 1
            
            else: continue

    answer = max(nextInfo.values())
    return answer