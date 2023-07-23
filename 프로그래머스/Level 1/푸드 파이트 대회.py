# https://school.programmers.co.kr/learn/courses/30/lessons/134240?language=python3
def solution(food):
    tmp = ""

    for i in range(1, len(food)):
        tmp += str(i)*(food[i] // 2)
    # print(tmp)

    return tmp+"0"+tmp[::-1]
