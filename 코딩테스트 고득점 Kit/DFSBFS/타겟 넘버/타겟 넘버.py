answer = 0

def DFS(arr, target, tot, level):
    global answer
    # 배열을 다 돌았다면
    if level == len(arr):
        if target == tot: # 원하는 값이 나왔다면
            answer += 1
        return
    
    DFS(arr, target, tot+arr[level], level+1)
    DFS(arr, target, tot-arr[level], level+1)
    return

def solution(numbers, target):
    DFS(numbers, target, 0, 0)
    return answer