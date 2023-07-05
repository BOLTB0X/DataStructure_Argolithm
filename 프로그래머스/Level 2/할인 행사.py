# https://school.programmers.co.kr/learn/courses/30/lessons/131127
def check(partArr, want, number):
    wDict = {}
    pDict = {}

    for p in partArr:
        if not p in pDict:
            pDict[p] = 1
        else:
            pDict[p] += 1

    for i in range(len(number)):
        wDict[want[i]] = number[i]

    return True if wDict == pDict else False


def solution(want, number, discount):
    answer = 0

    # 배열을 10개씩 자르면서 want, Number와 겹치는 걸 찾으면 됌
    for i in range(len(discount)-9):
        partArr = discount[i:i+10]

        if check(partArr, want, number):  # 다 되었다면
            answer += 1

    return answer
