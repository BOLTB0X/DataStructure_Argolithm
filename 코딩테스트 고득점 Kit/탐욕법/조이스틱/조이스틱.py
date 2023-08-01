def solution(name):
    answer = 0
    minMove = len(name)-1

    for i in range(len(name)):
        answer += min(ord(name[i]) - ord("A"), ord("Z") - ord(name[i])+1)
        next = i+1
        while next < len(name) and name[next] == "A":
            next += 1

        minMove = min(minMove, 2 * i + len(name) -
                      next, i + 2 * (len(name) - next))
    answer += minMove
    return answer
