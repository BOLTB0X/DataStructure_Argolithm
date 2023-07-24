# 2023 KAKAO BLIND RECRUITMENT 이모티콘 할인행사
from itertools import product

maxCnt = 0
maxTotDiscount = 0


def solution(users, emoticons):
    for per in product([10, 20, 30, 40], repeat=len(emoticons)):
        calculateEmoticon(users, emoticons, per)
    return [maxCnt, maxTotDiscount]


def calculateEmoticon(users, emoticons, per):
    global maxCnt
    global maxTotDiscount
    cnt = 0
    totDiscount = 0

    for user in users:
        tot = 0
        for i in range(len(emoticons)):
            if user[0] <= per[i]:
                tot += (emoticons[i]*(100 - per[i])/100)
            if user[1] <= tot:
                break

        # print(tot)
        # 가입이 1순위
        if tot >= user[1]:
            cnt += 1
            tot = 0
        totDiscount += tot

    # print(cnt, totDiscount)
    if cnt >= maxCnt:
        if cnt == maxCnt:
            maxTotDiscount = max(maxTotDiscount, totDiscount)
        else:
            maxTotDiscount = totDiscount
        maxCnt = cnt
    return
