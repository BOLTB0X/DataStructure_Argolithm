# 1541 잃어버린 괄호
# https://www.acmicpc.net/problem/1541
import sys
input = sys.stdin.readline


def solution(expression):
    ret = 0
    exp = expression.split('-')

    for i in range(len(exp)):
        splitedE = exp[i].split('+')
        tot = 0

        for se in splitedE:
            tot += int(se)

        if not i:
            ret += tot
        else:
            ret -= tot

    return ret


expression = input().rstrip()
print(solution(expression))
