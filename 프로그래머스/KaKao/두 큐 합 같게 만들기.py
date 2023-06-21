# 2022 KAKAO TECH INTERNSHIP 두 큐 합 같게 만들기
from collections import deque

def solution(queue1, queue2):
    answer = 0
    que1 = deque(queue1)
    que2 = deque(queue2)
    q1Tot = sum(queue1) # sum은 시간초과
    q2Tot = sum(queue2)
    
    # 큰넘걸 빼줌
    while True:
        # 답이 안나오는 경우
        # 두 큐가 다 돈 경우
        if answer > len(queue1)*4:
            return -1
        # 탈출 조건
        if q1Tot == q2Tot:
            break
        
        if q1Tot > q2Tot:
            ele = que1.popleft()
            que2.append(ele)
            q1Tot -= ele
            q2Tot += ele
            
        elif q1Tot < q2Tot:
            ele = que2.popleft()
            que1.append(ele)
            q1Tot += ele
            q2Tot -= ele

        answer += 1
    
    return answer