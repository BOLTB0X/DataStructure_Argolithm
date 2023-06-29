# 2020 KAKAO BLIND RECRUITMENT 문자열 압축
def solution(s):
    answer = len(s)  # for 최솟값

    for i in range(1, len(s)//2+1):
        tmp = ""
        cmp = s[:i]
        cnt = 1  # 반복되는 횟수
        # print(cmp)
        for j in range(i, len(s), i):
            if cmp == s[j:i+j]:
                cnt += 1  # 카운트
            else:  # 다른 문자로 압축해야할 때
                if cnt > 1:
                    cmp = (str(cnt) + cmp)

                tmp += cmp
                cmp = s[j:i+j]
                cnt = 1
        if cnt > 1:
            cmp = (str(cnt) + cmp)
        tmp += cmp
        cmp = s[j:i+j]
        cnt = 1
        # print(tmp)
        answer = min(answer, len(tmp))
    return answer
