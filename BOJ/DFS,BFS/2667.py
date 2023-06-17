# 2667 단지번호붙이기
# https://www.acmicpc.net/problem/2667
import sys
from collections import deque
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
board = []
dist = [[0]*N for _ in range(N)]
dir = [[1,0], [-1,0], [0,1], [0,-1]]
answer = [] # 정답

def BFS(y, x):
    que = deque()
    que.append((y, x))
    dist[y][x] = 1
    dep = 1

    while que:
        cy,cx = que.popleft()

        for d in dir:
            ny = cy + d[0]
            nx = cx + d[1]

            if ny < 0 or nx < 0 or ny >= N or nx >= N:
                continue

            if dist[ny][nx] != 0 or board[ny][nx] == "0":
                continue

            dist[ny][nx] = 1
            dep += 1
            que.append((ny, nx))
    
    return dep


# 맵 입력
for _ in range(N):
    board.append(input())

for i in range(N):
    for j in range(N):
        if board[i][j] == "1" and dist[i][j] == 0:
            answer.append(BFS(i,j))

answer.sort() # 정렬
print(len(answer))
for a in answer:
    print(a)
