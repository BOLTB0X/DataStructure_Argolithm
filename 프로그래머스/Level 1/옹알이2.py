# https://school.programmers.co.kr/learn/courses/30/lessons/133499
def solution(babbling):
    answer = 0
    words = ["aya", "ye", "woo", "ma"]

    for babb in babbling:
        for word in words:
            if word*2 not in babb:
                babb = babb.replace(word, " ")

        if babb.isspace():
            answer += 1
    return answer
