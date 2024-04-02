# 1920 수 찾기
# https://www.acmicpc.net/problem/1920

import sys
from collections import Counter

input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))

m = int(input())
targets = list(map(int, input().split()))

counter = Counter(a)
for target in targets:
    print(1 if target in counter else 0)
