# https://school.programmers.co.kr/learn/courses/30/lessons/161990?language=python3
def solution(wallpaper):
    answer = []
    lux, luy, rdx, rdy = float('inf'), float(
        'inf'), float('-inf'), float('-inf')

    for i in range(len(wallpaper)):
        for j in range(len(wallpaper[0])):
            if wallpaper[i][j] == "#":
                lux = min(lux, i)
                luy = min(luy, j)
                rdx = max(rdx, i)
                rdy = max(rdy, j)

    answer = [lux, luy, rdx+1, rdy+1]
    return answer
