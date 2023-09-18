// https://school.programmers.co.kr/learn/courses/30/lessons/12905?language=swift
import Foundation

func solution(_ board:[[Int]]) -> Int {
    var answer:Int = board[0][0]
    var board = board
    
    for i in 1..<board.count {
        for j in 1..<board[i].count {
            if board[i][j] == 1 {
                board[i][j] = 1 + min(board[i-1][j-1],board[i-1][j], board[i][j-1])
                answer = max(answer, board[i][j])
            }
        }
    }

    return answer*answer
}