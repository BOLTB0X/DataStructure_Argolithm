# 2018 KAKAO BLIND RECRUITMENT [3차] 파일명 정렬
def solution(files):
    answer = []
    splitedArr = []

    for file in files:
        h, n, t = fileSplie(file)
        splitedArr.append([h, n, t])

    # print(splitedArr)
    splitedArr.sort(key=lambda x: int(x[1]))
    splitedArr.sort(key=lambda x: x[0].lower())
    # print(splitedArr)

    for spl in splitedArr:
        answer.append("".join(spl))
    return answer


def fileSplie(file):
    tmp = ""
    HEAD, NUMBER, TAIL = "", "", ""
    eIdx = 0

    # 헤드 만들기
    for i in range(len(file)):
        if file[i].isdigit():
            HEAD = tmp
            eIdx = i
            break
        else:
            tmp += file[i]

    # print(HEAD)
    tmp = ""
    file = file[eIdx:]
    flag = 0

    for i in range(len(file)):
        if not file[i].isdigit():
            NUMBER = tmp
            eIdx = i
            tmp = ""
            break
        else:
            tmp += file[i]

    if len(tmp) > 0:  # 끝까지 간경우
        return (HEAD, tmp, TAIL)
    # print(NUMBER)
    TAIL = file[eIdx:]
    # print(TAIL)
    return (HEAD, NUMBER, TAIL)
