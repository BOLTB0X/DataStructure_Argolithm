#최대공약수
def gcd(a,b):
    if a%b==0:
        return b
    else:
        return gcd(b,a%b)

#최소공배수
def lcm(a,b):
    return a*b//gcd(a,b)

#3개 이상 최소공배수
def solution_lcm(arr):
    while True:
        arr.append(lcm(arr.pop(),arr.pop()))
        if len(arr)==1:
            return arr[0]