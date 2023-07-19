# 2018 KAKAO BLIND RECRUITMENT [3차] 압축
def solution(msg):
    answer = []
    alpDic = {chr(i+64): i for i in range(1, 27)}  # 1.
    searchStr = ""
    curNumber, idx = 27, 0

    while idx < len(msg):  # 2
        searchStr += msg[idx]

        if searchStr in alpDic:
            idx += 1
            continue
        else:
            alpDic[searchStr] = curNumber  # 4
            curNumber += 1
            answer.append(alpDic[searchStr[:-1]])  # 3
            searchStr = ""

    if len(searchStr) > 0:
        answer.append(alpDic[searchStr])
    return answer
