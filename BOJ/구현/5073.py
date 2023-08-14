# 5073 삼각형과 세 변
# https://www.acmicpc.net/problem/5073
import sys
input = sys.stdin.readline

while True:
    a, b, c = map(int, input().split())

    if a == 0 and b == 0 and c == 0:
        break

    if b + c <= a or a + c <= b or a + b <= c:
        print("Invalid")

    else:
        if a == b and b == c:
            print("Equilateral")
        elif (a == b and b != c) or (b == c and c != a) or (a == c and b != c):
            print("Isosceles")
        else:
            print("Scalene")
