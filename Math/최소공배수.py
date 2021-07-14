def gcd(number1,number2):
    if (number1%number2)==0:
        return number2
    else:
        return gcd(number2,number1%number2)

def lcm(number1, number2):
    return number1*number2//gcd(number1,number2)
