from collections import deque


def solution(priorities, location):
    answer = 0
    dq = deque([])

    for i in range(len(priorities)):
        dq.append((priorities[i], i))

    while dq:
        curVal, curIdx = dq.popleft()
        # print(curIdx, curVal)
        if dq and curVal < max(dq)[0]:
            dq.append((curVal, curIdx))
        else:
            answer += 1
            if curIdx == location:
                break

    return answer
