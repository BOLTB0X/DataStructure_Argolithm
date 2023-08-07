# 2021 카카오 채용연계형 인턴십 숫자 문자열과 영단어

def solution(s):
    answer = ""
    alpDic = {"zero": "0", "one": "1", "two": "2", "three": "3", "four": "4",
              "five": "5", "six": "6", "seven": "7", "eight": "8", "nine": "9"}
    tmp = ""

    for ch in s:
        if not ch in "0123456789":
            tmp += ch
            if len(tmp) > 2:
                if tmp in alpDic:
                    answer += alpDic[tmp]
                    tmp = ""
        else:
            answer += ch
    return int(answer)
