# 이진 변환 반복하기
# https://school.programmers.co.kr/learn/courses/30/lessons/70129
# 0제거
def removeZero(st):
    cnt = 0
    for s in st:
        if s == "0":
            cnt += 1
    return cnt

# 이진 변환


def tranBin(num):
    ret = ""

    while num > 0:
        ret += str(num % 2)
        num //= 2

    return ret[::-1]


def solution(s):
    answer = [0, 0]
    st = s

    while st != "1":
        answer[0] += 1  # 회차 시작
        # 0 제거
        answer[1] += removeZero(st)
        ss = "".join(st.split("0"))
        # 2진수 변환
        binStr = tranBin(len(ss))
        st = binStr
    return answer
