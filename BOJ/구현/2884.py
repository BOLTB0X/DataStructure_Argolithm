# 2884 알람 시계
# https://www.acmicpc.net/problem/2884
H,M=map(int,input().split())

if M>=45: # H상관없음
    print(H,M-45)
elif M<45 and H>0: # M이 작으므로 H-1
    print(H-1,15+M)
else: # H=0인경우 
    print(23,15+M)