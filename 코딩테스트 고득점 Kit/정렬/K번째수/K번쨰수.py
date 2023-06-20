def solution(array, commands):
    answer = []
    
    for com in commands:
        tmp = array[com[0] - 1 : com[1]]
        tmp.sort()
        answer.append(tmp[com[2] - 1])
        
    return answer