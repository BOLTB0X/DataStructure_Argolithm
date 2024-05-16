# 24090 알고리즘 수업 - 퀵 정렬 1
# https://www.acmicpc.net/problem/24090
import sys

sys.setrecursionlimit(int(1e6))
input = sys.stdin.readline


def quickSort(p, r):  # A[p..r]을 오름차순 정렬한다.
    if p >= r:
        return

    q = partition(p, r)  # 분할
    quickSort(p, q-1)  # 왼쪽 부분 배열 정렬
    quickSort(q+1, r)  # 오른쪽 부분 배열 정렬


def partition(p, r):
    global a, k, cnt
    x = a[r]  # 기준원소
    i = p-1  # i는 x보다 작거나 작은 원소들의 끝지점

    for j in range(p, r):  # j는 아직 정해지지 않은 원소들의 시작 지점
        if a[j] <= x:
            i += 1
            a[i], a[j] = a[j], a[i]  # i값 증가 후 A[i] <-> A[j] 교환
            cnt += 1

            if cnt == k:
                print(a[i], a[j])

    if i+1 != r:
        a[i+1], a[r] = a[r], a[i+1]  # i + 1과 r이 서로 다르면 A[i + 1]과 A[r]을 교환
        cnt += 1

        if cnt == k:
            print(a[i+1], a[r])

    return i+1


n, k = map(int, input().split())
a = list(map(int, input().split()))
cnt = 0
quickSort(0, len(a)-1)

if cnt < k:
    print(-1)
