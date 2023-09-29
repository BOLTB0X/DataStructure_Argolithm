# 2003 수들의 합 2
# https://www.acmicpc.net/problem/2003

N, M = map(int, input().split())
arr = list(map(int, input().split()))
left, right = 0, 0
answer = 0

while right < N:
    partSum = sum(arr[left:right+1])
    if partSum == M:
        answer += 1
        left += 1

    elif partSum > M:
        left += 1

    elif partSum < M:
        right += 1

print(answer)
