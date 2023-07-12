// 2019 카카오 개발자 겨울 인턴십 크레인 인형뽑기 게임
import Foundation

func solution(_ board:[[Int]], _ moves:[Int]) -> Int {
    var answer:Int = 0
    var board = board
    var stack:[Int] = []
    
    for move in moves {
        for i in 0..<board.count {
            if board[i][move-1] == 0 {
                continue
            } else {
                stack.append(board[i][move-1])
                board[i][move-1] = 0
                break
            }
        }
        
        while stack.count > 1 && stack[stack.count - 1] == stack[stack.count - 2] {
            stack.removeLast()
            stack.removeLast()
            answer += 2
        }
    }
    
    //print(board)
    //print(stack)
    
    return answer
}