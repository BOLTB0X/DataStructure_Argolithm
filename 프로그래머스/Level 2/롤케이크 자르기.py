# https://school.programmers.co.kr/learn/courses/30/lessons/132265
from collections import Counter


def solution(topping):
    answer = 0

    toppingDic = Counter(topping)
    slideDic = set()
    # print(toppingDic)
    for t in topping:
        toppingDic[t] -= 1
        slideDic.add(t)

        if toppingDic[t] == 0:
            toppingDic.pop(t)

        if len(slideDic) == len(toppingDic):
            answer += 1

    return answer
