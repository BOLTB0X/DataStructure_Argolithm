# 20125 쿠키의 신체 측정
# https://www.acmicpc.net/problem/20125
import sys
input = sys.stdin.readline

N = int(input())
board = [str(input()) for _ in range(N)]
waistEnd = 0


def solution(N, board):
    heartPos = [0, 0]
    bodyLen = [0, 0, 0, 0, 0]

    def findHeart():
        ret = [0, 0]

        for i in range(N):
            for j in range(N):
                if board[i][j] == "*":
                    ret[0] = i+2
                    ret[1] = j+1
                    return ret

    def findLeftArm(heartRow, heartCol):
        ret = 0

        for i in range(heartCol-1):
            if board[heartRow-1][i] == "*":
                ret += 1

        return ret

    def findRightArm(heartRow, heartCol):
        ret = 0

        for i in range(heartCol, N):
            if board[heartRow-1][i] == "*":
                ret += 1

        return ret

    def findWaist(heartRow, heartCol):
        ret = 0
        global waistEnd

        for i in range(heartRow, N):
            if board[i][heartCol-1] == "*":
                ret += 1
                waistEnd = i

        return ret

    def findLeftLeg(heartRow, heartCol):
        ret = 0

        for i in range(N-1, waistEnd, -1):
            if board[i][heartCol-2] == "*":
                ret += 1

        return ret

    def findRightLeg(heartRow, heartCol):
        ret = 0

        for i in range(N-1, waistEnd, -1):
            if board[i][heartCol] == "*":
                ret += 1

        return ret

    heartPos = findHeart()
    bodyLen[0] = findLeftArm(heartPos[0], heartPos[1])
    bodyLen[1] = findRightArm(heartPos[0], heartPos[1])
    bodyLen[2] = findWaist(heartPos[0], heartPos[1])
    bodyLen[3] = findLeftLeg(heartPos[0], heartPos[1])
    bodyLen[4] = findRightLeg(heartPos[0], heartPos[1])

    print(*heartPos)
    print(*bodyLen)
    return


solution(N, board)
