from collections import defaultdict
from itertools import combinations
from bisect import bisect_left


def solution(info, query):
    answer = []
    infoDic = defaultdict(list)

    for i in info:
        tmp = i.split(" ")
        tmpArr = tmp[:4]
        tmpScore = int(tmp[-1])

        for j in range(5):
            for com in combinations([0, 1, 2, 3], j):
                copyTmp = tmpArr.copy()
                for c in com:
                    copyTmp[c] = "-"

                tmpKey = ''.join(copyTmp)
                infoDic[tmpKey].append(tmpScore)

    for value in infoDic.values():
        value.sort()

    for q in query:
        q = q.replace("and", '')
        tmpQ = q.split()
        searchKey = ''.join(tmpQ[:4])
        searchValue = int(tmpQ[4])
        # print(searchKey, searchValue)
        cnt = 0
        if searchKey in infoDic:
            arr = infoDic[searchKey]
            idx = bisect_left(arr, searchValue)
            cnt = len(arr)-idx
        answer.append(cnt)

    return answer
