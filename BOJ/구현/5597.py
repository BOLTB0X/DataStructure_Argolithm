# 5597 과제 안 내신 분..?
# https://www.acmicpc.net/problem/5597
import sys

input = lambda :sys.stdin.readline().rstrip()
students = [0 for _ in range(31)]

for _ in range(28): # 입력은 총 28줄로 각 제출자(학생)의 출석번호
    studentIdx = int(input())
    students[studentIdx] = 1

for i in range(1,31):
    if students[i] == 0:
        print(i)