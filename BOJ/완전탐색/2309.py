# 2309 일곱 난쟁이
# https://www.acmicpc.net/problem/2309
import sys
input = lambda : sys.stdin.readline().rstrip()

heights = [] # 키 리스트

for _ in range(9):
    heights.append(int(input()))

# 완전탐색
for i in range(9):
    for j in range(i+1,9):
        # 다행스럽게도 일곱 난쟁이의 키의 합이 100
        if sum(heights) - heights[i] - heights[j] == 100:
            heights[i] = 0
            heights[j] = 0
            break

heights.sort() # 정렬

# 출력
for h in heights:
    if h == 0:
        continue
    print(h)