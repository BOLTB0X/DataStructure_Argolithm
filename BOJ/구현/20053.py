# 20053 최소, 최대 2
# https://www.acmicpc.net/problem/20053
import sys

input = lambda: sys.stdin.readline().rstrip()

T = int(input())

for _ in range(T):
    N = int(input())
    nums = list(map(int,input().split()))
    print("{} {}".format(min(nums), max(nums)))