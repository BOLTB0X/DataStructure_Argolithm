# 2022 KAKAO BLIND RECRUITMENT 신고 결과 받기
# level 1
# https://school.programmers.co.kr/learn/courses/30/lessons/92334

def solution(id_list, report, k):
    answer = []
    idDict = {}  # 본인이 신고해서 정지당한
    idCountDict = {}  # 아이디당 신고 당한
    reportDict = {}  # 신고를 저장할 딕셔너리

    for id in id_list:  # 딕셔너리 초기화
        idDict[id] = 0
        idCountDict[id] = 0
        reportDict[id] = []

    # 아이디당 신고한 거 체크
    for r in report:
        a, b = r.split()  # 분리

        if not b in reportDict[a]:  # 중복 방지
            reportDict[a].append(b)

    # 이제 유저별 신고당한 횟수를 체크
    for (key, value) in reportDict.items():
        for v in value:
            idCountDict[v] += 1

    # print(reportDict)
    # print(idCountDict)

    # 여기서 본인이 신고한 넘들 중 k 이상 당한 넘들을 체크
    for (key, value) in reportDict.items():
        cnt = 0
        for v in value:
            if idCountDict[v] >= k:
                cnt += 1
        idDict[key] = cnt  # 신고 당한 놈들 수를 넣어줌

    # 정답에 넣어줌
    for (key, value) in idDict.items():
        answer.append(value)
    return answer
