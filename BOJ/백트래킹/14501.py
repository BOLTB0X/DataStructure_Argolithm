# 14501 퇴사
# https://www.acmicpc.net/problem/14501
import sys
def input(): return sys.stdin.readline().rstrip()


N = int(input())
T, P = [], []
answer = -1

for _ in range(N):
    a, b = map(int, input().split())
    T.append(a)
    P.append(b)


def DFS(cur, totPay, curPay):
    global answer
    if cur == N:
        answer = max(answer, totPay)
    elif cur > N:
        answer = max(answer, totPay - curPay)

    for i in range(cur, N):
        DFS(i+T[i], totPay+P[i], P[i])

    return


DFS(0, 0, 0)
print(answer)
