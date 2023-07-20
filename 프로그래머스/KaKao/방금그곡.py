# 2018 KAKAO BLIND RECRUITMENT [3차] 방금그곡
import math


def solution(m, musicinfos):
    answer = ''
    candiPlay = 0
    m = transMelody(m)

    for info in musicinfos:
        i = info.split(",")  # 시작, 끝, 제목, 코드
        # print(i)
        playTime = getPlayTime(i[0], i[1])
        melody = transMelody(i[3] * math.ceil(playTime / len(i[3])))[:playTime]
        # print(m, melody)

        if m in melody or melody in m:  # 있다면
            if candiPlay < playTime:
                answer = i[2]
                candiPlay = playTime

    if len(answer) == 0:
        answer = "(None)"
    return answer


def getPlayTime(startTime, endTime):
    eh1, eh2 = int(endTime[:2]) * 60, int(endTime[3:])
    sh1, sh2 = int(startTime[:2]) * 60, int(startTime[3:])
    return (eh1 + eh2) - (sh1 + sh2)


def transMelody(melody):  # C과 같은 #붙은 멜로디 구분을 위한 메소드
    ret = melody.replace('C#', 'c').replace('D#', 'd').replace(
        'F#', 'f').replace('G#', 'g').replace('A#', 'a')
    return ret
