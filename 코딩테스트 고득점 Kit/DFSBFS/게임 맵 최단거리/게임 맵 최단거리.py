from collections import deque

dir = [[-1,0],[1,0],[0,-1],[0,1]]

def solution(maps):
    answer = 0
    r = len(maps) 
    c = len(maps[0])
    
    # BFS
    que = deque()
    que.append([0,0])
    
    while que:
        cy, cx = que.popleft()
        
        for d in dir:
            ny = cy + d[0]
            nx = cx + d[1]
            
            if 0 <= ny < r and 0 <= nx < c:
                if maps[ny][nx] == 1:
                    maps[ny][nx] = maps[cy][cx] + 1
                    que.append([ny, nx])
    
    answer = maps[-1][-1] if maps[-1][-1] != 1 else -1
    return answer
