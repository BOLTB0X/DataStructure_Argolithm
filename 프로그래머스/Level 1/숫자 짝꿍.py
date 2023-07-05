# https://school.programmers.co.kr/learn/courses/30/lessons/131128
def solution(X, Y):
    answer = ""
    tmpArr = []
    xDict = {}
    yDict = {}

    for x in X:
        if not x in xDict:
            xDict[x] = 1
        else:
            xDict[x] += 1

    for y in Y:
        if not y in yDict:
            yDict[y] = 1
        else:
            yDict[y] += 1

    # print(xDict)
    # print(yDict)

    for (key, value) in xDict.items():
        if key in yDict:
            minLen = min(xDict[key], yDict[key])
            for _ in range(minLen):
                tmpArr.append(key)
            # print(minLen)
    # print(tmpArr)

    if not tmpArr:
        return "-1"
    tmpArr.sort(reverse=True)
    answer = "".join(tmpArr)
    return answer if answer[0] != "0" else "0"
