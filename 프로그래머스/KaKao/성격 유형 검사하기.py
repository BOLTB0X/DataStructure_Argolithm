# 2022 KAKAO TECH INTERNSHIP 성격 유형 검사하기

def getIndex(st):
    if st == "R" or st == "T":
        return 0
    elif st == "C" or st == "F":
        return 1
    elif st == "J" or st == "M":
        return 2
    else:
        return 3

def solution(survey, choices):
    answer = ''
    choicesScore = [0,3,2,1,0,1,2,3]
    jipyo = [{"R": 0, "T": 0}, {"C": 0, "F": 0}, {"J": 0, "M": 0}, {"A": 0, "N": 0}]
    
    for i in range(len(survey)):
        tmp = survey[i]
        idx = getIndex(tmp[0])
        if choices[i] > 4: # 크다면
            
            jipyo[idx][survey[i][1]] += choicesScore[choices[i]]
        elif choices[i] < 4:
            jipyo[idx][survey[i][0]] += choicesScore[choices[i]]

    #print(jipyo)

    for j in jipyo:
        tmp = dict(sorted(j.items(), key=lambda x: (-x[1], x[0])))
        answer += list(tmp)[0]
    return answer

print(solution(["AN", "CF", "MJ", "RT", "NA"], [5, 3, 2, 7, 5]))