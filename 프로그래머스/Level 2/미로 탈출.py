# https://school.programmers.co.kr/learn/courses/30/lessons/159993
from collections import deque

def solution(maps):
    answer = 0
    dir = [[1,0],[-1,0],[0,1],[0,-1]] # 방향
    dist = [[0] * len(maps[0]) for _ in range(len(maps))] # 방문리스트
    
    def BFS(y, x, ty, tx):
        que = deque([(y,x)]) # 큐 생성
        
        while que:
            cy, cx = que.popleft()
            
            if ty == cy and tx == cx:
                break
            
            for d in dir:
                ny = cy + d[0]
                nx = cx + d[1]
            
                # 범위 밖
                if ny < 0 or nx < 0 or ny >= len(maps) or nx >= len(maps[0]):
                    continue
            
                # 벽 
                if maps[ny][nx] == "X" or dist[ny][nx] != 0:
                    continue
                
                dist[ny][nx] = dist[cy][cx] + 1
                que.append((ny, nx))
             
    # 출발지점과 탈출 지점을 찾아야함
    sy, sx, ly, lx, ey, ex = 0,0,0,0,0,0
    for i in range(len(maps)):
        for j in range(len(maps[0])):
            if maps[i][j] == "S":
                sy, sx = i, j
            elif maps[i][j] == "E":
                ey, ex = i, j
            elif maps[i][j] == "L":
                ly,lx = i, j
    
    dist[sy][sx] = 0
    BFS(sy, sx, ly, lx) # 시작점으로 호출
    if dist[ly][lx]: # 레버 도달 체크
        answer += dist[ly][lx]
        dist = [[0] * len(maps[0]) for _ in range(len(maps))] # 방문리스트 초기화
        BFS(ly, lx, ey, ex)
    else:
        return -1
        
    if dist[ey][ex]: # 목적기 도달 체크
        answer += dist[ey][ex]
    else:
        return -1
    
    return answer