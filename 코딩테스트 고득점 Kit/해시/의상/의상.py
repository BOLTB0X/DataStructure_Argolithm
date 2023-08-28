def solution(clothes):
    answer = 1

    dic = {clothe[1]: [] for clothe in clothes}

    for clothe in clothes:
        dic[clothe[1]].append(clothe[0])

    # print(dic)

    for value in dic.values():
        answer *= (len(value)+1)

    return answer-1
