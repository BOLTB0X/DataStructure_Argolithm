# 1991 트리 순회
# https://www.acmicpc.net/problem/1991
import sys
def input(): return sys.stdin.readline().rstrip()


treeDic = {}
N = int(input())


def solutuion(N):
    global treeDic

    for n in range(N):
        root, left, right = input().split()
        treeDic[root] = [left, right]

    preorder("A")
    print()
    inorder("A")
    print()
    postorder("A")


def preorder(root):  # 전위 순회
    # (루트) (왼쪽 자식) (오른쪽 자식)
    if root != ".":
        print(root, end='')
        preorder(treeDic[root][0])  # left
        preorder(treeDic[root][1])  # right


def inorder(root):  # 중위 순회
    # (왼쪽 자식) (루트) (오른쪽 자식)
    if root != ".":
        inorder(treeDic[root][0])
        print(root, end="")
        inorder(treeDic[root][1])


def postorder(root):  # 후위 순회
    # (왼쪽 자식) (오른쪽 자식) (루트)
    if root != ".":
        postorder(treeDic[root][0])
        postorder(treeDic[root][1])
        print(root, end="")


solutuion(N)
