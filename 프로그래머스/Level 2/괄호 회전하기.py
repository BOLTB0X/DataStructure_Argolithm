# https://school.programmers.co.kr/learn/courses/30/lessons/76502
def check(s):
    stack = []
    for ss in s:
        if ss == "(" or ss == "[" or ss == "{":
            stack.append(ss)
        else:
            if not stack:
                return False
            elif ss == ")" and stack[-1] == "(":
                stack.pop()
            elif ss == "]" and stack[-1] == "[":
                stack.pop()
            elif ss == "}" and stack[-1] == "{":
                stack.pop()
            else:
                return False
    if stack:
        return False
    return True


def solution(s):
    answer = 0
    s = list(s)

    for _ in range(1, len(s)):  # x (0 ≤ x < (s의 길이)) 칸만큼 회전
        if check(s):  # 올바른 괄호
            answer += 1

        # 회전
        s.append(s.pop(0))
    return answer
