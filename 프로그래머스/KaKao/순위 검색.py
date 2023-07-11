# 2021 KAKAO BLIND RECRUITMENT 순위 검색
from collections import defaultdict
from itertools import combinations
from bisect import bisect_left  # 이분탐색


def solution(info, query):
    answer = []
    infoDict = defaultdict(list)

    for i in info:
        tmpI = i.split(" ")
        tmpKey = tmpI[:-1]  # 조건들
        # print(tmpKey)
        tmpValue = int(tmpI[-1])  # 점수

        for j in range(5):  # 0부터하는 이유는 전부 다 "-" 처리 할수 있어서
            for com in combinations([0, 1, 2, 3], j):
                tmpArr = tmpKey.copy()
                for c in com:
                    tmpArr[c] = "-"

                # print(tmpArr)
                tmpKeyStr = "".join(tmpArr)
                infoDict[tmpKeyStr].append(tmpValue)

    # print(infoDict)
    for value in infoDict.values():
        value.sort()

    for q in query:
        q = q.replace("and", "")
        qArr = q.split()

        qKey = "".join(qArr[:-1])
        qValue = int(qArr[-1])
        cnt = 0

        if qKey in infoDict:
            targetArr = infoDict[qKey]
            tatgetIdx = bisect_left(targetArr, qValue)
            cnt = len(targetArr) - tatgetIdx

        answer.append(cnt)
    return answer
