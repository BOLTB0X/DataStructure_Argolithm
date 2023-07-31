def solution(s):
    answer = True
    stack = []

    for i in range(len(s)):
        if s[i] == "(":
            stack.append("(")
        else:
            if stack:
                stack.pop()
            else:
                return False

    return True if not stack else False
