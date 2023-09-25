# 2529 부등호
# https://www.acmicpc.net/problem/2529
import sys
input = sys.stdin.readline

maxRes = "-9876543210"
minRes = "9876543210"


def DFS(num, depth):
    global maxRes, minRes
    if depth == k+1:
        maxRes = num if int(num) > int(maxRes) else maxRes
        minRes = num if int(num) < int(minRes) else minRes
        return

    for i in range(10):
        if visited[i]:
            continue

        if depth == 0:
            visited[i] = True
            DFS(num+str(i), depth+1)
            visited[i] = False
        else:
            if A[depth - 1] == "<" and int(num[depth-1]) < i:
                visited[i] = True
                DFS(num+str(i), depth+1)
                visited[i] = False

            if A[depth - 1] == ">" and int(num[depth-1]) > i:
                visited[i] = True
                DFS(num+str(i), depth+1)
                visited[i] = False


k = int(input())
A = list(input().split())
visited = [False] * 10

DFS("", 0)

print(maxRes)
print(minRes)
