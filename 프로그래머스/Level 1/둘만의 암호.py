# https://school.programmers.co.kr/learn/courses/30/lessons/155652?language=python3
def solution(s, skip, index):
    answer = ''
    
    for ss in s:
        moveCnt = 0
        curCh = ord(ss)
        
        while moveCnt < index:
            curCh += 1
            
            if curCh > ord('z'):
                curCh = ord('a')
            
            if chr(curCh) in skip:
                continue
                
            moveCnt += 1
        
        #print(chr(curCh))
        answer += chr(curCh)
    return answer