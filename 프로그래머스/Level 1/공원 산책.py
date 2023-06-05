def inRange(y, x, r, c):      
    return (y >= 0 and x >= 0 and y<r and x < c)
        

def solution(park, routes):
    cy,cx = -1,-1 # 현재 좌표
    lenY, lenX = len(park), len(park[0])
    
    # 현재 좌표 찾기
    for i in range(lenY):
        for j in range(lenX):
            if park[i][j] == "S":
                cy, cx = i, j
                break
        if cy != -1 and cx != -1:
            break
    
    # 명령을 하나씩 확인하며 진행
    for r in routes:
        d, l = r[0], int(r[2])
        flag = 0
        
        if d == "E":
            if not inRange(cy, cx+l, lenY, lenX):
                    continue
            for i in range(1, l+1):
                if park[cy][cx+i] == "X":
                    flag = 1
                    break
                    
            if flag == 0:
                cx += l
            
        elif d == "W":
            if not inRange(cy, cx-l, lenY, lenX):
                    continue
            for i in range(1, l+1):
                if park[cy][cx-i] == "X":
                    flag = 1
                    break
                    
            if flag == 0:
                cx -= l
            
        elif d == "S":
            if not inRange(cy+l, cx, lenY, lenX):
                    continue
            for i in range(1, l+1):
                if park[cy+i][cx] == "X":
                    flag = 1
                    break
                    
            if flag == 0:
                cy += l
        
        elif d == "N":
            if not inRange(cy-l, cx, lenY, lenX):
                    continue
            for i in range(1, l+1):
                if park[cy-i][cx] == "X":
                    flag = 1
                    break
                    
            if flag == 0:
                cy -= l
                
    return [cy, cx]