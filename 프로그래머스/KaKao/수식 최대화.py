from itertools import permutations


def getList(expression):
    expList = []
    tmpValue = ""
    for exp in expression:
        if exp in "+-*":
            expList.append(tmpValue)
            expList.append(exp)
            tmpValue = ""
        else:
            tmpValue += exp

    if tmpValue != "":
        expList.append(tmpValue)

    return expList


def operationExp(a, b, op):
    if op == "+":
        return str(int(a)+int(b))
    elif op == "-":
        return str(int(a)-int(b))
    return str(int(a)*int(b))


def getValue(per, expression):
    expList = getList(expression)

    for p in per:
        stack = []

        while expList:
            tmp = expList.pop(0)

            if stack and tmp == p:
                stack.append(operationExp(stack.pop(), expList.pop(0), tmp))
            else:
                stack.append(tmp)
        expList = stack

    return abs(int(expList[0]))


def solution(expression):
    answer = 0

    for per in permutations(["+", "-", "*"], 3):
        answer = max(answer, getValue(per, expression))
    return answer
