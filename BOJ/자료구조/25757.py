# 25757 임스와 함께하는 미니게임
# https://www.acmicpc.net/problem/25757
import sys
input = sys.stdin.readline

N, YFO = input().split()
playerArr = [input() for _ in range(int(N))]
playerArr = list(set(playerArr))

if YFO == "Y":  # 윷놀이 2
    print(len(playerArr))
elif YFO == "F":  # 같은 그린 찾기 3
    print(len(playerArr) // 2)
elif YFO == "O":  # 원카드 4
    print(len(playerArr) // 3)
