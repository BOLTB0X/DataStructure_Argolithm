# 2021 카카오 채용연계형 인턴십 거리두기 확인하기
flag = True
dir = [[1, 0], [-1, 0], [0, 1], [0, -1]]


def DFS(place, visited, y, x, level):
    global flag

    if not flag:
        return

    if level >= 2:
        flag = True
        return

    for d in dir:
        ny = y + d[0]
        nx = x + d[1]

        # 범위 내
        if ny >= 0 and ny < 5 and nx >= 0 and nx < 5:
            if place[ny][nx] == "X" or visited[ny][nx]:
                continue

            if level < 2 and place[ny][nx] == "P":
                flag = False
                return

            if place[ny][nx] == "O":
                visited[ny][nx] = True
                DFS(place, visited, ny, nx, level+1)
    return


def checkPlace(place):
    global flag
    flag = True
    visited = [[False] * 5 for _ in range(5)]

    for i in range(5):
        for j in range(5):
            # 사람 발견
            if place[i][j] == "P":
                visited[i][j] = True
                DFS(place, visited, i, j, 0)

            if not flag:
                return 0

    return 1 if flag else 0


def solution(places):
    answer = []

    for place in places:
        answer.append(checkPlace(place))
    return answer
