# 1717 집합의 표현
# https://www.acmicpc.net/problem/1717
import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline


def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]


def union(parent, a, b):
    a = find(parent, a)
    b = find(parent, b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b


n, m = map(int, input().split())
parentNodes = [i for i in range(n+1)]

for _ in range(m):
    cmd, a, b = map(int, input().split())

    if cmd == 0:
        union(parentNodes, a, b)
    else:
        if find(parentNodes, a) == find(parentNodes, b):
            print("YES")
        else:
            print("NO")
