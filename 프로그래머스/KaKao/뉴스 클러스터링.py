# 2018 KAKAO BLIND RECRUITMENT [1차] 뉴스 클러스터링
from collections import Counter


def solution(str1, str2):
    str1Arr, str2Arr = [], []

    for i in range(len(str1)-1):
        if str1[i].isalpha() and str1[i+1].isalpha():
            str1Arr.append(str1[i:i+2].lower())

    for i in range(len(str2)-1):
        if str2[i].isalpha() and str2[i+1].isalpha():
            str2Arr.append(str2[i:i+2].lower())
    # print(str1Arr)
    # print(str2Arr)

    counter1 = Counter(str1Arr)
    counter2 = Counter(str2Arr)
    # print(counter1, counter2)

    inter = list((counter1 & counter2).elements())
    union = list((counter1 | counter2).elements())
    # print(inter, union)

    return 65536 if len(union) == 0 and len(inter) == 0 else int(len(inter)/len(union) * 65536)
