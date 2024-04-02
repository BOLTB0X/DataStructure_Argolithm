# 10809 알파벳 찾기
# https://www.acmicpc.net/problem/10809
import sys

input = sys.stdin.readline


def solution(s):
    ret = [-1]*26

    for i in range(len(s)):
        if ret[ord(s[i])-97] != -1:
            continue
        ret[ord(s[i])-97] = i

    return ret


s = input().rstrip()
print(*solution(s))
