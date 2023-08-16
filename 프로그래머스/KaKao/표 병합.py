def solution(commands):
    answer = []
    table = [["EMPTY"] * 51 for _ in range(51)]
    merged = [[(i, j) for j in range(51)] for i in range(51)]

    for command in commands:
        cmd = command.split(" ")

        if cmd[0] == "UPDATE":
            if len(cmd) == 4:
                r, c = merged[int(cmd[1])][int(cmd[2])]
                table[r][c] = cmd[3]

            elif len(cmd) == 3:
                for i in range(1, 51):
                    for j in range(1, 51):
                        if table[i][j] == cmd[1]:
                            table[i][j] = cmd[2]

        elif cmd[0] == "MERGE":
            r1, c1 = merged[int(cmd[1])][int(cmd[2])]
            r2, c2 = merged[int(cmd[3])][int(cmd[4])]

            if r1 == r2 and c1 == c2:
                continue

            if table[r1][c1] == "EMPTY" and table[r2][c2] != "EMPTY":
                table[r1][c1] = table[r2][c2]

            for i in range(1, 51):
                for j in range(1, 51):
                    if merged[i][j] == (r2, c2):
                        merged[i][j] = (r1, c1)

        elif cmd[0] == "UNMERGE":
            r, c = merged[int(cmd[1])][int(cmd[2])]
            preValue = table[r][c]

            for i in range(1, 51):
                for j in range(1, 51):
                    if merged[i][j] == (r, c):
                        merged[i][j] = (i, j)
                        table[i][j] = "EMPTY"
            table[int(cmd[1])][int(cmd[2])] = preValue

        elif cmd[0] == "PRINT":
            r, c = merged[int(cmd[1])][int(cmd[2])]
            answer.append(table[r][c])

    return answer
