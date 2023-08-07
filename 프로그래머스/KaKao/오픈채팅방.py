# 2019 KAKAO BLIND RECRUITMENT 오픈채팅방
def solution(record):
    answer = []
    stateDic = {}

    for r in record:
        tmp = r.split(" ")
        # print(tmp)

        if len(tmp) > 2:
            stateDic[tmp[1]] = tmp[2]

    for r in record:
        tmp = r.split(" ")

        if tmp[0] == "Enter":
            answer.append(stateDic[tmp[1]]+"님이 들어왔습니다.")
        elif tmp[0] == "Leave":
            answer.append(stateDic[tmp[1]]+"님이 나갔습니다.")

    return answer
