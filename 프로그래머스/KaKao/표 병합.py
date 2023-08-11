def solution(commands):
    answer = []
    table = [["EMPTY"] * 50 for _ in range(50)]
    merged = [[(i, j) for j in range(50)] for i in range(50)]
    
    for command in commands:
        cmd = command.split(" ")
        #print(cmd)
        
        if cmd[0] == "UPDATE":
            if len(cmd) == 4:
                x, y = merged[int(cmd[1])-1][int(cmd[2])-1]
                table[x][y] = cmd[3]
            else:
                for i in range(50):
                    for j in range(50):
                        if table[i][j] == cmd[1]:
                            table[i][j] = cmd[2]
    
        elif cmd[0] == "MERGE":
            x1,y1 = merged[int(cmd[1])-1][int(cmd[2])-1]
            x2,y2 = merged[int(cmd[3])-1][int(cmd[4])-1]
            if table[x1][y1] == "EMPTY":
                table[x1][y1] = table[x2][y2]
            
            for i in range(50):
                for j in range(50):
                    if merged[i][j] == (x2, y2):
                        merged[i][j] = (x1, y1)
            
        elif cmd[0] == "UNMERGE":
            x, y = merged[int(cmd[1])-1][int(cmd[2])-1]
            preValue = table[x][y]
            
            for i in range(50):
                for j in range(50):
                    if merged[i][j] == (x, y):
                        merged[i][j] = (i, j)
                        table[i][j] = "EMPTY"
            table[int(cmd[1])-1][int(cmd[2])-1] = preValue
        
        elif cmd[0] == "PRINT":
            x,y = merged[int(cmd[1])-1][int(cmd[2])-1]
            answer.append(table[x][y])
            
    return answer