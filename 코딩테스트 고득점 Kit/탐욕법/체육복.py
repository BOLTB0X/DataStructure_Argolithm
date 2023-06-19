def solution(n, lost, reserve):
    answer = 0
    arr = [1]*n
    
    for l in lost: # 두고온 넘들
        arr[l-1] -= 1
    for r in reserve:
        arr[r-1] += 1
    
    for i in range(len(arr)):
        if arr[i] == 0: # 체육복이 없다면
            if i > 0 and arr[i-1] >= 2:
                arr[i-1] -= 1
                arr[i] += 1
                
            elif i < n-1 and arr[i+1] >= 2: # 여분이 있다면
                    arr[i+1] -= 1
                    arr[i] += 1
    
    for a in arr:
        if a > 0:
            answer += 1
    return answer