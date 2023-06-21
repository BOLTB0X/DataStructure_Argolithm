# 2021 카카오 채용연계형 인턴십 숫자 문자열과 영단어

def solution(s):
    answer = ""
    alpDict = {"zero": "0", "one": "1", "two": "2", "three": "3", "four": "4", "five": "5", "six": "6", "seven": "7", "eight": "8", "nine": "9"}
    
    word = ""
    for ss in s:
        if ss.isdigit(): # 숫자인 경우
            answer += ss
        else:
            word += ss
            if len(word) > 2 and word in alpDict:
                answer += alpDict[word]
                word = ""
            
    return int(answer)