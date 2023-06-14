# https://school.programmers.co.kr/learn/courses/30/lessons/169199
from collections import deque # 덱 이용

def solution(board):
    answer = -1
    dir = [[-1,0],[1,0],[0,-1],[0,1]] # 상, 하, 좌, 우 4방향 중 하나를 선택
    dist = [[0] * len(board[0]) for _ in range(len(board))] # 방문 리스트
    # 맨 끝에 부딪힐 때까지 미끄러져 이동하는 것을 한 번의 이동으로 침
    que = deque(())
    
    # 로봇 위치 찾기
    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == 'R':
                dist[i][j] = 1
                que.append((i,j))

    while que: # 큐가 비어질때까지
        cx,cy = que.popleft()
        
        if board[cx][cy] == "G": # 골인지점에 도달했을 경우
            answer = dist[cx][cy] - 1 # 구분을 위해 첫 시작할때 +1을 했기에
            break
        
        for d in dir:
            nx,ny = cx, cy
            while True: # 미끄어지는 것이니, 루프에 보드 안이고 벽에 부딫치기 전까지 반복
                nx += d[0]
                ny += d[1]
                
                # 범위초과
                if nx < 0 or ny < 0 or nx >= len(board) or ny >= len(board[0]):
                    nx -= d[0]
                    ny -= d[1]
                    break
                    
                # 벽이라면
                if board[nx][ny] == "D":
                    nx -= d[0]
                    ny -= d[1]
                    break
            
            if dist[nx][ny] == 0: # 이동한 곳이 한번도 안 간곳이면 넣어줌
                dist[nx][ny] = dist[cx][cy] + 1
                que.append((nx,ny))
    
    return answer