res = 0
def DFS(number, arr, visited, cur):
    global res
    
    if len(arr) == 3 and sum(arr) == 0:
        res += 1
        return
    
    for i in range(cur,len(number)):
        if visited[i]:
            continue
        
        arr.append(number[i])
        visited[i] = True
        DFS(number, arr, visited, i+1)
        visited[i] = False
        arr.pop()
    return

def solution(number):
    answer = 0
    visited = [False] * len(number)
    
    DFS(number, [], visited, 0)
    answer = res
    return answer