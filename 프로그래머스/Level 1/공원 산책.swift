// https://school.programmers.co.kr/learn/courses/30/lessons/172928
import Foundation

func solution(_ park:[String], _ routes:[String]) -> [Int] {
    var answer:[Int] = [-1, -1]
    var board:[[String]] = []
    let row = park.count
    let col = park[0].count

    func getBoard() {
        for i in 0..<row {
            board.append(park[i].map{ String($0)})
        }
    }
    
    func getCurPosition() -> [Int] {
        var tmp:[Int] = [-1, -1]
        
        for i in 0..<row {
            for j in 0..<col {
                if board[i][j] == "S" {
                    tmp[0] = i
                    tmp[1] = j
                    break
                }
            }
        }
        
        return tmp
    }
    
    func inRange(_ x: Int, _ y: Int) -> Bool {
        return x >= 0 && y >= 0 && x < row && y < col
    }
    
    getBoard()
    answer = getCurPosition()
    
    for route in routes {
        let dir = String(route.first!)
        let n = Int(String(route.last!))!
        
        if dir == "E" {
            if !inRange(answer[0], answer[1]+n) {
                continue
            }
            var flag = 0
            for d in 1...n {
                if board[answer[0]][answer[1]+d] == "X" {
                    flag = 1
                    break
                }
            }
            
            if flag == 0 {
                answer[1] += n
            }
        } else if dir == "W" {
            if !inRange(answer[0], answer[1]-n) {
                continue
            }
            var flag = 0
            for d in 1...n {
                if board[answer[0]][answer[1]-d] == "X" {
                    flag = 1
                    break
                }
            }
            
            if flag == 0 {
                answer[1] -= n
            }
        } else if dir == "S" {
            if !inRange(answer[0]+n, answer[1]) {
                continue
            }
            var flag = 0
            for d in 1...n {
                if board[answer[0]+d][answer[1]] == "X" {
                    flag = 1
                    break
                }
            }
            
            if flag == 0 {
                answer[0] += n
            }
        } else if dir == "N" {
            if !inRange(answer[0]-n, answer[1]) {
                continue
            }
            var flag = 0
            for d in 1...n {
                if board[answer[0]-d][answer[1]] == "X" {
                    flag = 1
                    break
                }
            }
            
            if flag == 0 {
                answer[0] -= n
            }
        }
    }
    return answer
}