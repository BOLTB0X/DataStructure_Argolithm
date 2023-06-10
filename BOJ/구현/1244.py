# 1244 스위치 켜고 끄기
# https://www.acmicpc.net/problem/1244
import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
switchsList = list(map(int, input().split()))
M = int(input())

# 가독성을 위한 메소드
def switchToggle(idx):
    if switchsList[idx] == 0:
        switchsList[idx] = 1
    else:
        switchsList[idx] = 0
    return

for _ in range(M):
    a,b = map(int,input().split())

    if a == 1: # 남학생이면
        for i in range(N):
            if not (i+1)%b: # b의 배수이면
                switchToggle(i)
        
    else: # 여학생이면
        idx = b-1
        switchToggle(idx)
        
        # 문제를 잘못 이해했음
        # 대칭으로 같은거일때 가장 긴 케이스로 바꿔야함
        for i in range(1, (N//2)+1):
            # 인덱스 조심
            if idx+i >= N or idx-i < 0:
                break # 이건 안되는 경우
            
            if switchsList[idx+i] == switchsList[idx-i]:
                switchToggle(idx+i)
                switchToggle(idx-i)
            else:
                break

# 출력을 잘못하고 있었음
# 스위치의 상태를 1번 스위치에서 시작하여 마지막 스위치까지 한 줄에 20개씩 출력
for i in range(N):
    print(switchsList[i], end = " ")
    if (i+1) % 20 == 0:
        print()
