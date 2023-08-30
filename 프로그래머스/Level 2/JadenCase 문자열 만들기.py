def solution(s):
    answer = []
    s = s.split(" ")

    for i in range(len(s)):
        if s[i]:
            answer.append(s[i][0].upper()+s[i][1:].lower())
        else:
            answer.append(s[i])
    return " ".join(answer)
