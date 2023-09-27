# 1541 잃어버린 괄호
# https://www.acmicpc.net/problem/1541
input_data=input().split('-') #일단 -로 나눔

ans=0
for i in input_data[0].split('+'):
    ans+=int(i)

for i in input_data[1:]:
    for j in i.split('+'):
        ans -= int(j)
        
print(ans)