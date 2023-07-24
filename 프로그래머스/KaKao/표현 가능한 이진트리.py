# 2023 KAKAO BLIND RECRUITMENT 표현 가능한 이진트리
def solution(numbers):
    answer = []
    binNumbers = [bin(number)[2:] for number in numbers]
    binArr = [2**x - 1 for x in range(50)]
    # print(binNumbers)
    # print(binArr)

    def search(number):
        size = len(number)
        if size == 1 or "1" not in number or "0" not in number:
            return True

        mid = size // 2
        if number[mid] == "0":
            return False

        return search(number[:mid]) and search(number[mid+1:])

    for number in binNumbers:
        size = len(number)
        for b in binArr:
            if b >= size:
                number = '0' * (b - size) + number
                break

        answer.append(1 if search(number) else 0)
    return answer
