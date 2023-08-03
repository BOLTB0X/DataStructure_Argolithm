def solution(citations):
    answer = 0
    citations.sort(reverse=True)

    for c in citations:
        if c > answer:
            answer += 1
        else:
            break

    return answer
