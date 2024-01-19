# https://school.programmers.co.kr/learn/courses/30/lessons/258711
def solution(edges):
    answer = [0, 0, 0, 0] # 정점, 도넛, 막대, 8자
    
    # 생성점: in: 0, out: 2개 이상
    # 막대: in: 1개, out: 0
    # 8자: in: 2개 이상, out: 2개 이상
    # 도넛: in = out
    
    nodeDict = {}
    for a,b in edges:
        if not nodeDict.get(a):
            nodeDict[a] = [0, 0]
            
        if not nodeDict.get(b):
            nodeDict[b] = [0, 0]
            
        # nodeCount의 value [0, 0]
        # (idx: 0) = in, (idx: 1) = out
        nodeDict[a][1] += 1
        nodeDict[b][0] += 1
    
    #print(nodeCount)
    
    for key, inoutInfo in nodeDict.items():
        # 생성점
        if inoutInfo[0] == 0 and inoutInfo[1] >= 2:
            answer[0] = key
        
        # 막대
        elif inoutInfo[0] > 0 and inoutInfo[1] == 0:
            answer[2] += 1 
        
        # 8자
        elif inoutInfo[0] >= 2 and inoutInfo[1] >= 2:
            answer[3] += 1
    
    answer[1] = nodeDict[answer[0]][1] - answer[2] - answer[3]
    return answer