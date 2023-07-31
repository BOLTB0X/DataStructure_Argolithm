# 같은 숫자는 싫어
def solution(arr):
    answer = []

    for a in arr:
        if len(answer) == 0 or (len(answer) > 0 and answer[-1] != a):
            answer.append(a)
        continue

    return answer
