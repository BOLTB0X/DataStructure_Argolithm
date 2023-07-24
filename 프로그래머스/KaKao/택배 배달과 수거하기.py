# 2023 KAKAO BLIND RECRUITMENT 택배 배달과 수거하기
def solution(cap, n, deliveries, pickups):
    answer = 0
    deliveries = deliveries[::-1]
    pickups = pickups[::-1]

    curD, curP = 0, 0

    for i in range(n):
        curD += deliveries[i]
        curP += pickups[i]

        while curD > 0 or curP > 0:
            curD -= cap
            curP -= cap

            answer += 2*(n - i)
        # print(curD, curP)
    return answer
