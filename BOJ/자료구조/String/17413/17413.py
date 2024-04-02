# 17413 단어뒤집기 2
# https://www.acmicpc.net/problem/17413
import sys
input = sys.stdin.readline

stack = []
words = list(input())

i = 0
start = 0

while i < len(words):
    # 열린 괄호이면
    if words[i] == "<":
        i += 1
        # 닫힌 괄호를 만날때 까지
        while words[i] != ">":
            i += 1
        i += 1

    # 알파벳인 경우
    elif words[i].isalnum():
        start = i
        while i < len(words) and words[i].isalnum():
            i += 1
        # 범위에 있는 것들
        tmp = words[start:i]
        # 뒤집는다
        tmp.reverse()
        words[start:i] = tmp

    # 괄호도 아니고 알파벳,숫자도 아닌 것
    else:
        i += 1

# 출력
print("".join(words))
