def solution(n):
    def hanoi(number, start, end):
        if number == 1:
            return [[start, end]]

        another = 0
        for i in range(1, 4):
            if i != start and i != end:
                another = i
                break
        # n-1개짜리 탑을 다른 지점에 옮기고
        # n번째 원판을 목표지점에 옮기고,
        # n-1개를 목표 지점으로 옮겨여험
        return hanoi(number-1, start, another) + [[start, end]] + hanoi(number-1, another, end)
    return hanoi(n, 1, 3)
