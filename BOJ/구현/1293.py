# 1293 오리
# https://www.acmicpc.net/problem/12933
import sys
def input(): return sys.stdin.readline().rstrip()


inputStr = input()
answer = 0
visited = [False] * len(inputStr)  # 방문리스트


def isDuck(start):
    global answer
    quack = "quack"
    j = 0
    flag = True

    for i in range(start, len(inputStr)):
        # quack 이 순이면
        if inputStr[i] == quack[j] and not visited[i]:
            visited[i] = True
            if inputStr[i] == "k":  # 다 나왔다면
                if flag:
                    answer += 1
                    flag = False
                j = 0  # 초기화
                continue
            j += 1

    return


if len(inputStr) % 5:  # 애초에 안되는 경우
    print(-1)
else:
    for i in range(len(inputStr)):
        # 얘가 되는 지 체크해야하
        if inputStr[i] == "q" and not visited[i]:
            isDuck(i)

    # 오리가 없다면
    if not all(visited) or answer == 0:
        print(-1)
    else:
        print(answer)
