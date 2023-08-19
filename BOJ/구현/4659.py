# 4659 비밀번호 발음하기
# https://www.acmicpc.net/problem/4659
import sys
input = sys.stdin.readline


def check(st):
    cnt = 0

    # 1. 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
    for s in st:
        if s == "a" or s == "e" or s == "i" or s == "o" or s == "u":
            cnt += 1

    if cnt < 1:
        print("<{}> is not acceptable.".format(st))
        return

    # 2. 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
    cnt = 0
    for i in range(len(st)-2):
        if st[i] in "aeiou" and st[i+1] in "aeiou" and st[i+2] in "aeiou":
            cnt = 1
        elif not st[i] in "aeiou" and not st[i+1] in "aeiou" and not st[i+2] in "aeiou":
            cnt = 1

    if cnt == 1:
        print("<{}> is not acceptable.".format(st))
        return

    # 3. 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
    cnt = 0
    for i in range(len(st)-1):
        if st[i] == st[i+1]:
            if st[i] == "e" or st[i] == "o":
                continue
            else:
                cnt = 1

    if cnt == 1:
        print("<{}> is not acceptable.".format(st))
        return

    print("<{}> is acceptable.".format(st))
    return


while True:
    inputStr = input().strip()

    if inputStr == "end":
        break
    else:
        check(inputStr)
