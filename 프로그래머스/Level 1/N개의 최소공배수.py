# https://school.programmers.co.kr/learn/courses/30/lessons/12953
def gcd(a,b): #최대공약수
    if a%b==0:
        return b
    else:
        return gcd(b,a%b)

def lcm(a,b): #최소공배수
    return a*b//gcd(a,b)

def solution(arr):
    while True:
        arr.append(lcm(arr.pop(),arr.pop()))
        if len(arr) == 1:
            return arr[0]