def gcd(num1,num2):
    if (num1%num2)==0:
        return num2
    else:
        return gcd(num2,num1%num2)

def solution(num1,num2,num3):
    return gcd(gcd(num1,num2),num3)