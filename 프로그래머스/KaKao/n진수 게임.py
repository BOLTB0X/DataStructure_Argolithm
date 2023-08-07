# 2018 KAKAO BLIND RECRUITMENT [3차] n진수 게임
def convert(num, base):
    tmp = "0123456789ABCDEF"
    q, r = divmod(num, base)

    if q == 0:
        return tmp[r]
    else:
        return convert(q, base) + tmp[r]


def solution(n, t, m, p):
    answer = ''
    newT = ""

    for i in range((m*t)+1):
        newT += convert(i, n)

    idx = p - 1

    while len(answer) < t:
        answer += newT[idx]
        idx += m

    return answer
