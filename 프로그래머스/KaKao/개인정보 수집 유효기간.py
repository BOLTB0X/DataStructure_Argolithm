# 2023 KAKAO BLIND RECRUITMENT 개인정보 수집 유효기간
def transTotalDays(date):
    year,mon,day = map(int,date.split(".")) # 오늘 분리
    return year*28*12 + mon*28 + day

def getCurentTerms(terms, alp):
    for i in range(len(terms)):
        tAlp, tMon = terms[i].split()
        if tAlp == alp:
            return int(tMon) * 28 # 기간을 리턴
        
def solution(today, terms, privacies):
    answer = []
    # 모든 달은 28일까지 있다고 가정
    
    tDay = transTotalDays(today) # 일로 변환
    
    for i in range(len(privacies)): # 순회
        tNotice, term = privacies[i].split() # data와 구분을 쪼갬
        # 편의를 위해
        pDay = transTotalDays(tNotice) # 비교해아할 곳 날로 환산
        pDay += getCurentTerms(terms, term) # 현재 등급에 따른 기간
    
        if tDay >= pDay:
            answer.append(i+1)
    return answer