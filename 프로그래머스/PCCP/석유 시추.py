# https://school.programmers.co.kr/learn/courses/30/lessons/250136
from collections import deque

visited = [[0] * 500 for i in range(500)]
oilGrup = []

row, col = 500, 500

def BFS(land, x, y):
    global oilGrup, visited
    
    ret = 1
    colSet = set()
    que = deque([])
    
    dir = [[1, 0], [-1, 0], [0, 1], [0, -1]]
    que.append((x, y))
    colSet.add(y)
    visited[x][y] = True
    
    while que:
        cx, cy = que.popleft()
        
        for d in dir:
            nx = cx + d[0]
            ny = cy + d[1]
            
            if nx < 0 or ny < 0 or nx >= row or ny >= col:
                continue
            
            if visited[nx][ny] or land[nx][ny] == 0: 
                continue
            
            ret += 1
            visited[nx][ny] = True
            colSet.add(ny)
            que.append((nx, ny))
    
    
    oilGrup.append((ret, colSet))
    
    return

def init(land):
    global row, col
    
    row, col = len(land), len(land[0])
    
    return

def makeOilGruop(land):
    for i in range(row):
        for j in range(col):
            if land[i][j] == 1 and not visited[i][j]:
                BFS(land, i, j)
                
    return

def solution(land):
    answer = 0
    
    init(land)
    makeOilGruop(land)
    
    colAmounts = [0] * col
    #print(oilGrup)
    
    for oilSize, colSet in oilGrup:
        for c in colSet:
            colAmounts[c] += oilSize
            answer = max(colAmounts[c], answer)
        
    #print(colAmounts)
    return answer
