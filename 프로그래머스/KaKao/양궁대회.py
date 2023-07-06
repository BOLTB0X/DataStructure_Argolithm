# 2022 KAKAO BLIND RECRUITMENT 양궁대회
from itertools import combinations_with_replacement


def getScore(lion, aporch):
    aScore, lScore = 0, 0

    for i in range(11):
        if lion[i] == 0 and aporch[i] == 0:
            continue

        if lion[i] > aporch[i]:
            lScore += (10 - i)
        else:
            aScore += (10 - i)

    return (lScore, aScore)


def solution(n, info):
    answer = []
    maxDiff = -1  # 가장 낮은 점수를 더 많이 맞힌 경우를 위해

    for combi in list(combinations_with_replacement(range(11), n)):
        lionInfo = [0] * 11

        for c in combi:
            lionInfo[10-c] += 1

        lScore, aScore = getScore(lionInfo, info)

        if lScore > aScore and lScore - aScore > maxDiff:
            maxDiff = lScore - aScore
            answer = lionInfo

    return answer if answer else [-1]
