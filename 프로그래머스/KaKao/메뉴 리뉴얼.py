combi = []  # 조합

# DFS로 조합


def DFS(order, orderCombi, cur, level):
    if len(orderCombi) == level:  # 탈출 조건
        tmp = list(orderCombi)  # 정렬을 위해
        tmp.sort()
        combi.append("".join(tmp))
        return

    for i in range(cur, len(order)):
        DFS(order, orderCombi+order[i], i+1, level)


def solution(orders, course):
    answer = []
    global combi  # 전역변수 이용

    for c in course:  # 코스요리 개수부터 하고
        # 이에 대한 조합을 함
        for order in orders:  # 각 주문 메뉴에 대한 만들어야할 코스 요리수의 조합 생성
            DFS(order, "", 0, c)

        combi = list(set(combi))  # 중복 제거
        # print(combi)

        # 이 조합으 각 주문 메뉴에 있는지 체크
        combiDict = {}  # 나온 카운트를 담아둘 딕셔너리
        for com in combi:
            for order in orders:
                # 떨어져있는 경우도 체크하기 위해
                if all(c in order for c in com):
                    if not com in combiDict:  # 생성
                        combiDict[com] = 1
                    else:  # 카운트
                        combiDict[com] += 1
        # print(combiDict
        if combiDict:  # 생성 되었다면
            maxValue = max(combiDict.values())
            if maxValue >= 2:
                for (key, value) in combiDict.items():
                    if value == maxValue:
                        answer.append(key)
        combi = []  # 다음것을 위해

    answer.sort()  # 알파벳 정렬
    return answer
