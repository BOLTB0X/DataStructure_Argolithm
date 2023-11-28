// 2019 카카오 개발자 겨울 인턴십 크레인 인형뽑기 게임
// https://school.programmers.co.kr/learn/courses/30/lessons/64061
import Foundation

func solution(_ board:[[Int]], _ moves:[Int]) -> Int {
    var answer:Int = 0
    var board = board
    var stack: [Int] = []
    
    for move in moves {
        for i in 0..<board.count {
            if board[i][move-1] == 0 {
                continue
            }
            
            stack.append(board[i][move-1])
            board[i][move-1] = 0
            break
        }
        while stack.count > 1 && stack[stack.count-1] == stack[stack.count-2] {
            answer += 2
            stack.removeLast()
            stack.removeLast()
        }
    }
    return answer
}