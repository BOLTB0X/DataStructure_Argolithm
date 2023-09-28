# 2490 윷놀이
# https://www.acmicpc.net/problem/2490
for i in range(3):
    li=list(map(int,input().split()))
    f = b = 0
    for j in range(len(li)):
        if li[j]==1:
            b+=1
        else:
            f+=1
    if f==1 and b==3:
        print('A')
    elif f==b==2:
        print('B')
    elif f==3 and b==1:
        print('C')
    elif f==4:
        print('D')
    else:
        print('E')