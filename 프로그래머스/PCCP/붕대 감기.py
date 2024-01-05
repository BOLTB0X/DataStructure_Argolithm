# PCCP 기출문제 [PCCP 기출문제] 1번
# https://school.programmers.co.kr/learn/courses/30/lessons/250137
def solution(bandage, health, attacks):
    answer = 0
    time, curHealth, success, cur = 0, health, 0, 0

    while cur < len(attacks):
        time += 1
        if isActtack(time, attacks[cur][0]):  # 공격
            curHealth -= attacks[cur][1]
            success = 0
            cur += 1

            if curHealth <= 0:
                answer = -1
                break
        else:  # 회복
            success += 1
            addHealth = bandage[1]
            if success == bandage[0]:
                addHealth += bandage[2]
                success = 0

            curHealth += addHealth
            if curHealth >= health:
                curHealth = health
        # print(time, curHealth)
    # print(curHealth)
    if answer != -1:
        answer = curHealth
    return answer


def isActtack(time, currentAttacks):
    if currentAttacks == time:
        return True
    else:
        return False
