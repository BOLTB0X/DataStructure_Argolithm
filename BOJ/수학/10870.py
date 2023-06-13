# 10870 피보나치 수 5
# https://www.acmicpc.net/problem/10870

import sys
input = lambda: sys.stdin.readline().rstrip()

# 재귀: 탑 다운
def fiboRecur(number):
    if number <= 1:
        return number
    return fiboRecur(number-1)+fiboRecur(number-2) 
    
# 반복문
def fiboLoop(number):
    fList = [0, 1]

    for i in range(2, number+1):
        fList.append(fList[i-2]+fList[i-1])
    
    return fList[number]

n = int(input())
print(fiboRecur(n))
#print(fiboLoop(n))