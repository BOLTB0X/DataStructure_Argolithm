# 2021 KAKAO BLIND RECRUITMENT 메뉴 리뉴얼
# level 2
# https://school.programmers.co.kr/learn/courses/30/lessons/72411
combi = []

# 조합 만들기


def DFS(n, s, idx, st):
    if len(st) == n:
        tmp = list(st)
        tmp.sort()
        combi.append(''.join(tmp))
        return

    for i in range(idx, len(s)):
        DFS(n, s, i+1, st+s[i])


def solution(orders, course):
    answer = []
    global combi

    for c in course:
        for i in range(len(orders)):
            cnt = 0
            # 2갯수만큼 쪼개기
            DFS(c, orders[i], 0, "")

        combi = list(set(combi))  # 중복 제거
        # print(combi)

        comDict = {}

        for com in combi:  # 딕셔너리로 체크
            for o in orders:
                if all(c in o for c in com):
                    if not com in comDict:
                        comDict[com] = 1
                    else:
                        comDict[com] += 1
        # print(comDict)
        if comDict:
            maxValue = max(comDict.values())  # 최댓값 찾기
            for (key, value) in comDict.items():
                if maxValue >= 2 and value == maxValue:
                    answer.append(key)
        combi = []

    # print(answer)
    # 알파벳 순으로 오름차순 정렬
    answer.sort()
    return answer
