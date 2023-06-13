# https://school.programmers.co.kr/learn/courses/30/lessons/178871
def solution(players, callings):
    answer = players
    # 선수 : 등수
    curRanking = { b : a for a, b in enumerate(players)}
    #print(curRanking)
    for c in callings:
        curIdx = curRanking[c] # 현재 불린 선수 위치
        
        curRanking[answer[curIdx]] -= 1
        curRanking[answer[curIdx-1]] += 1 # 등수 바꿔주고
        
        answer[curIdx], answer[curIdx-1] = answer[curIdx-1], answer[curIdx]

    return answer