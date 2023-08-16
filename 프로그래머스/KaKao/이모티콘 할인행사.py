from itertools import product

maxCnt = 0
maxValue = 0


def calculateEmoticons(users, emoticons, per):
    global maxCnt, maxValue
    cnt, value = 0, 0

    for user in users:
        tot = 0
        for i in range(len(per)):
            if user[0] <= per[i]:
                tot += (emoticons[i] * (100 - per[i])/100)

        if tot >= user[1]:
            cnt += 1
        else:
            value += tot

    if cnt >= maxCnt:
        if cnt == maxCnt:
            maxValue = max(value, maxValue)
        else:
            maxValue = value
        maxCnt = cnt

    return


def solution(users, emoticons):
    answer = []

    for per in product([10, 20, 30, 40], repeat=len(emoticons)):
        calculateEmoticons(users, emoticons, per)
    answer = [maxCnt, maxValue]
    return answer
