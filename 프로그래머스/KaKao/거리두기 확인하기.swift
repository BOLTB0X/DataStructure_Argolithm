// 2021 카카오 채용연계형 인턴십 거리두기 확인하기
import Foundation

var flag: Bool = true
var dir: [[Int]] = [[1,0], [-1,0], [0,1], [0,-1]]

func DFS(_ board: [[String]], _ visited: [[Bool]], _ cy: Int, _ cx: Int, _ level: Int) {
    if !flag {
        return
    }
    
    if level == 2 {
        return
    }
    
    var visited = visited
    
    for d in dir {
        let ny = cy + d[0]
        let nx = cx + d[1]
        
        if ny >= 0 && nx >= 0 && ny < 5 && nx < 5 {
            if board[ny][nx] == "X" || visited[ny][nx] {
                continue
            }
            
            if level < 2 && board[ny][nx] == "P" {
                flag = false
                return
            }
            
            visited[ny][nx] = true
            var cnt = level + 1
            DFS(board, visited, ny, nx, cnt)
        }
    }
    return
}

func checkPlace(_ board: [[String]]) -> Int {
    flag = true 
    var visited = Array(repeating: Array(repeating: false, count: 5), count: 5)
    for i in 0..<5 {
        for j in 0..<5 {
            if board[i][j] == "P" {
                visited[i][j] = true
                DFS(board, visited, i, j, 0)
                if !flag { // 거리두기 실패
                    return 0
                }
            }
        }
    }
    return 1
}

func solution(_ places:[[String]]) -> [Int] {
    var answer:[Int] = []
    
    for place in places {
        var place = place.map { $0.map { String($0) } } // 편의용
        answer.append(checkPlace(place))
    }
    
    return answer
}