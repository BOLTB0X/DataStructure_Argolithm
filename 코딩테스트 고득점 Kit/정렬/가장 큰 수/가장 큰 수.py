def solution(numbers):
    answer = ''
    str_num = [str(i) for i in numbers]

    str_num.sort(key=lambda n: n * 3, reverse=True)

    for s in str_num:
        answer += s

    return answer if answer[0] != "0" else "0"
