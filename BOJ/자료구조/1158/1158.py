# 1158 요세푸스 문제
# https://www.acmicpc.net/problem/1158

import sys
from collections import deque
input = lambda :sys.stdin.readline().rstrip()

# 1 2 3 4 5 6 7
# 4 5 6 7 1 2 -> 3
# 7 1 2 4 5 -> 6
# 4 5 7 1 -> 2
# 1 4 5 -> 7
# 1 4 -> 5
# 4 -> 1
#  -> 4

# 큐 이용
# k-1 번 만큼 앞에 원소를 뒤로 옮겨줌
# 맨 앞에 원소를 pop해주고 이를 정답 리스트에 넣어줌
# queue의 길이가 k보다 작아지면
# 그냥 순서대로 넣어줌

N, K = map(int,input().split())
que = deque([i for i in range(1,N+1)]) # 큐 생성
answer = []

while que: # 큐를 돌릴수 있을 때까지
    for _ in range(K-1): # K번 째 넘이 최상단에 가려면 K-1번 돌려야함
        que.append(que.popleft())
    answer.append(str(que.popleft())) # 죽을 넘을 넣어줌

# 출력
print("<", ", ".join(answer)[:], ">", sep = "")
