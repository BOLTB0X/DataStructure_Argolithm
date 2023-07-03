# https://school.programmers.co.kr/learn/courses/30/lessons/12899
def solution(n):
    answer = ''

    # 3진법 이용
    # 0 대신 4로
    while n:
        if n % 3:
            answer += str(n % 3)
            n //= 3
        else:
            answer += "4"
            n //= 3
            n -= 1  # 이를 안해주면 1 들어가짐
    return answer[::-1]
