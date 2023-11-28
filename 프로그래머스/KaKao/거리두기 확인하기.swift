// 2021 카카오 채용연계형 인턴십 거리두기 확인하기
// https://school.programmers.co.kr/learn/courses/30/lessons/81302
import Foundation

func solution(_ places:[[String]]) -> [Int] {
    var answer:[Int] = []
    
    for place in places {
        answer.append(isProtectSafetyDist(place))
    }
    return answer
}

func isProtectSafetyDist(_ place:[String]) -> Int {
    var ret: Bool = true
    var visited = Array(repeating: Array(repeating: false, count: 5), count: 5)
    
    let dir = [[1, 0], [-1, 0], [0, 1], [0, -1]]
    let place = place.map { Array($0) }
    
    func DFS(_ x:Int, _ y:Int, _ depth: Int) {
        if !ret || depth == 2 { return }
        
        for d in dir {
            let nx = x + d[0]
            let ny = y + d[1]
            
            if nx < 0 || ny < 0 || ny >= 5 || nx >= 5 { continue }
            
            if visited[nx][ny] || place[nx][ny] == "X" { continue }
            
            if depth < 2 && place[nx][ny] == "P" {
                ret = false
                return
            }
            
            visited[nx][ny] = true
            DFS(nx, ny, depth + 1)
        }
    }
    
    for i in 0..<5 {
        for j in 0..<5 {
            if place[i][j] == "P" {
                visited[i][j] = true
                DFS(i, j, 0)
            }
            
            if !ret { break }
        }
        if !ret { break }
    }
    
    return ret ? 1 : 0
}