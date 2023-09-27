# 2810 컵홀더
# https://www.acmicpc.net/problem/2810
# 문자열?

N = int(input())
sit=input()
cnt=0
sCnt=sit.count('S')
lCnt=sit.count('LL')

if lCnt>0:
    print(sCnt+lCnt+1)
else:
    print(N)