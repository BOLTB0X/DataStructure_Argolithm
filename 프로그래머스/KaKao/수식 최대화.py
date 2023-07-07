# 2020 카카오 인턴십 수식 최대화
from itertools import permutations


def transList(st):
    ret = []
    tmp = ""

    for s in st:
        if s == "*" or s == "-" or s == "+":
            ret.append(tmp)
            ret.append(s)
            tmp = ""
        else:
            tmp += s

    ret.append(tmp)
    return ret


def opreationFunc(a, b, op):
    if op == "*":
        return str(int(a) * int(b))
    elif op == "+":
        return str(int(a) + int(b))
    else:
        return str(int(a) - int(b))


def getValue(expression, Op):
    exp = transList(expression)

    for op in Op:  # exp 리스트 중 op가 나온 부분만 연산
        # 나머진 stack에 넣어두고 교체
        stack = []

        while exp:
            tmp = exp.pop(0)  # 첫번쨰
            if stack and tmp == op:
                stack.append(opreationFunc(stack.pop(), exp.pop(0), tmp))
            else:
                stack.append(tmp)

        exp = stack
        # print(exp)
    return abs(int(exp[0]))


def solution(expression):
    answer = 0

    priorityOpArr = list(permutations(["*", "+", "-"], 3))

    for priorityOp in priorityOpArr:
        answer = max(answer, getValue(expression, priorityOp))

    return answer
