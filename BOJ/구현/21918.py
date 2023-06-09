# 21918 전구
# https://www.acmicpc.net/problem/21918
import sys
input = lambda :sys.stdin.readline().rstrip()

# 1번 명령어: i번째 전구의 상태를 x로 변경한다.
# 2번 명령어: l번째부터 r번째까지의 전구의 상태를 변경한다. (켜져있는 전구는 끄고, 꺼져있는 전구는 킨다.)
# 3번 명령어: l번째부터 r번째까지의 전구를 끈다.
# 4번 명령어: l번째부터 r번째까지의 전구를 킨다.

N, M = map(int, input().split())
lightList = list(map(int, input().split()))

for _ in range(M):
    comm = list(map(int, input().split()))

    if comm[0] == 1:
        lightList[comm[1]-1] = comm[2]

    elif comm[0] == 2:
        for i in range(comm[1]-1,comm[2]):
            if lightList[i] == 0:
                lightList[i] = 1
            else:
                lightList[i] = 0
    elif comm[0] == 3:
        for i in range(comm[1]-1,comm[2]):
            lightList[i] = 0

    elif comm[0] == 4:
        for i in range(comm[1]-1,comm[2]):
            lightList[i] = 1

print(*lightList) # 출력