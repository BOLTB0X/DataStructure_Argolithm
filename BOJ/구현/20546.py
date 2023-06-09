# 20546 기적의 매매법
# https://www.acmicpc.net/problem/20546
import sys
input = lambda:sys.stdin.readline().rstrip()

# 준현이는 살수 있는 만큼 삼
# 성민이는
# 1. 현재 있는 돈으로 살때 살수 있을 만큼 삼
# 2. 3일 연속 상승하면 전량 매도
# 3. 3일 연속 하락하면 1번으로 삼

N = int(input()) # 각자의 현금
budgetList = list(map(int, input().split()))
jMoney, sMoney = N, N # 갖고 있는 돈
jScore, sScore = 0, 0 # 준현이, 성민이
answer = [0,0]
# 0 1 2 3 4 5 6 7 8 9 10 11 12 13

for i in range(len(budgetList)):
    # 준현이가 살수 있다면
    if budgetList[i] <= jMoney:
        jScore += (jMoney//budgetList[i])
        jMoney -= (jMoney//budgetList[i]) * budgetList[i] 
    
    # 성민
    if i - 2 >= 0:
        # 하락
        # 3 6 14
        if budgetList[i] < budgetList[i-1] < budgetList[i-2]:
            if sMoney >= budgetList[i]:
                sScore += sMoney//budgetList[i]
                sMoney -= (sMoney // budgetList[i]) * budgetList[i]
        
        # 상승 -> 팔아야함
        elif budgetList[i] > budgetList[i-1] > budgetList[i-2]:
            sMoney += (sScore * budgetList[i])
            sScore = 0
                
# 점수 계산
answer[0] = jMoney + jScore * budgetList[-1]
answer[1] = sMoney + sScore * budgetList[-1]

#print(answer)
print("BNP" if answer[0] > answer[1] else "TIMING" if answer[0] < answer[1] else "SAMESAME")