# 20920 영단어 암기는 괴로워
# https://www.acmicpc.net/problem/20920
import sys

input = sys.stdin.readline


def solution(n, m, words):
    dic = {}

    for w in words:
        if len(w) < m:
            continue
        if w in dic:
            dic[w] += 1
        else:
            dic[w] = 1

    sortedArr = sorted(dic.items(), key=lambda x: (-x[1], -len(x[0]), x[0]))

    res = [print(ele[0]) for ele in sortedArr]
    return


n, m = map(int, input().split())
words = []

for _ in range(n):
    words.append(input().rstrip())

solution(n, m, words)
