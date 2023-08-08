def solution(participant, completion):
    answer = ''
    partDic = {}

    for part in participant:
        if part in partDic:
            partDic[part] += 1
        else:
            partDic[part] = 1

    for com in completion:
        partDic[com] -= 1

    for key, value in partDic.items():
        if value == 1:
            answer = key

    return answer
