# 1463 1로 만들기
# https://www.acmicpc.net/problem/1463
n = int(input())
m = [0 for _ in range(n+1)]
#DP 보텀업 문제조건을 나눠서 생각해라

for i in range(2,n+1):
    #현재의 수에서 1을 빼는 경우
    m[i] = m[i-1]+1
    if i%2 == 0 and m[i] > m[i//2] + 1 :
        m[i] = m[i//2]+1
    if i%3 == 0 and m[i] > m[i//3] + 1 :
        m[i] = m[i//3] + 1

print(m[n])