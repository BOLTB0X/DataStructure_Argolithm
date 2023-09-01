from collections import deque


def solution(rectangle, characterX, characterY, itemX, itemY):
    answer = 0
    board = [[-1] * 102 for _ in range(102)]

    def BFS():
        que = deque()
        dist = [[0] * 102 for _ in range(102)]
        dir = [[1, 0], [-1, 0], [0, 1], [0, -1]]

        que.append((characterX*2, characterY*2))
        dist[characterX*2][characterY*2] = 1

        while que:
            cx, cy = que.popleft()

            if cx == itemX * 2 and cy == itemY * 2:
                return dist[cx][cy] // 2

            for d in dir:
                nx = cx+d[0]
                ny = cy+d[1]

                if nx < 0 or ny < 0 or nx >= 102 or ny >= 102:
                    continue

                if dist[nx][ny] or board[nx][ny] != 1:
                    continue

                que.append((nx, ny))
                dist[nx][ny] = dist[cx][cy] + 1

        return

    for rect in rectangle:
        x1, y1, x2, y2 = rect[0]*2, rect[1]*2, rect[2]*2, rect[3]*2

        for i in range(x1, x2+1):
            for j in range(y1, y2+1):
                # 테두리 안
                if x1 < i and x2 > i and y1 < j and y2 > j:
                    board[i][j] = 0
                elif board[i][j] != 0:
                    board[i][j] = 1

    answer = BFS()

    return answer
