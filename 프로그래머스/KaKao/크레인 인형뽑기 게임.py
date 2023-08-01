def solution(board, moves):
    answer = 0
    stack = []

    for move in moves:
        for i in range(len(board)):
            if board[i][move-1] != 0:
                stack.append(board[i][move-1])
                board[i][move-1] = 0
                break

        while len(stack) > 1 and stack[-1] == stack[-2]:
            stack.pop()
            stack.pop()
            answer += 2

    return answer
