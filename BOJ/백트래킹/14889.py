# 14889 스타트와 링크
# https://www.acmicpc.net/problem/14889
import sys
def input(): return sys.stdin.readline().rstrip()


N = int(input())
board = []
visited = [False] * N
answer = 2001

for _ in range(N):
    tmp = list(map(int, input().split()))
    board.append(tmp)


def DFS(cur, depth):
    global answer
    if depth == N // 2:
        sTot, lTot = 0, 0

        for i in range(N):
            for j in range(N):
                if visited[i] and visited[j]:
                    sTot += board[i][j]
                elif not visited[i] and not visited[j]:
                    lTot += board[i][j]

        answer = min(answer, abs(sTot-lTot))
        return

    for i in range(cur, N):
        if visited[i]:
            continue
        visited[i] = True
        DFS(i+1, depth+1)
        visited[i] = False


DFS(0, 0)
print(answer)
