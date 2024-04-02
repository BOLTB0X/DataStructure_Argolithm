# 11866 요세푸스 문제 0
# https://www.acmicpc.net/problem/11866
import sys
from collections import deque

input = sys.stdin.readline

# 1 2 3 4 5 6 7
# 4 5 6 7 1 2 -> 3
# 7 1 2 4 5 -> 6
# 4 5 7 1 -> 2
# 1 4 5 -> 7
# 1 4 -> 5


def solution1(n, k):
    ret = []
    que = deque([i for i in range(1, n+1)])

    while len(que):
        for _ in range(k-1):
            que.append(que.popleft())

        ret.append(str(que.popleft()))
        # print('que:', que)

    return '<'+', '.join(ret)+'>'


def solution2(n, k):
    ret = []
    sequ = [i for i in range(1, n+1)]
    idx = 0

    while sequ:
        idx += k-1

        if idx >= len(sequ):
            idx %= len(sequ)

        ret.append(str(sequ.pop(idx)))

    return '<'+', '.join(ret)+'>'


n, k = map(int, input().split())
print(solution1(n, k))
print(solution2(n, k))
