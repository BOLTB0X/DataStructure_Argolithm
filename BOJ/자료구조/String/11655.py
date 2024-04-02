# 11655 ROT13
# https://www.acmicpc.net/problem/11655
import sys

input = sys.stdin.readline

s = input()

for element in s:
    if element.isupper():
        ch = chr((ord(element)+13) if element <= 'M' else ord(element)-13)
        print(ch, end='')

    elif element.islower():
        ch = chr((ord(element)+13) if element <= 'm' else ord(element)-13)
        print(ch, end='')

    else:
        print(element, end='')
