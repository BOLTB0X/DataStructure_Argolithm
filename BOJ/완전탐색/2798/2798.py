# 2798 블랙잭
# https://www.acmicpc.net/problem/2798

import sys
input = lambda: sys.stdin.readline().rstrip()

N,M = map(int,input().split()) 
numberArr = list(map(int, input().split()))
answer = -1

# 완전탐색
for i in range(N-2):
    for j in range(i+1, N-1):
        for k in range(j+1,N):
            if numberArr[i]+numberArr[j]+numberArr[k] <= M: #  M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합
                answer = max(answer, numberArr[i]+numberArr[j]+numberArr[k])

print(answer)
