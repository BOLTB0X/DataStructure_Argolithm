from collections import deque


def solution(bridge_length, weight, truck_weights):
    answer = 0
    bridge = deque([])
    cur = 0

    while cur < len(truck_weights):
        if bridge and bridge[0][1] == bridge_length:
            bridge.popleft()

        if sum(b[0] for b in bridge) + truck_weights[cur] <= weight:
            bridge.append((truck_weights[cur], 0))
            cur += 1

        for _ in range(len(bridge)):
            t1, t2 = bridge.popleft()
            bridge.append((t1, t2+1))
        answer += 1

    return answer + bridge_length
