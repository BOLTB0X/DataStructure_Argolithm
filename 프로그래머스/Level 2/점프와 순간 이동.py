# https://school.programmers.co.kr/learn/courses/30/lessons/12980
def solution(n):
    ans = 0

    while n != 0:
        if not n % 2:
            n //= 2
        else:
            n -= 1
            ans += 1

    return ans
