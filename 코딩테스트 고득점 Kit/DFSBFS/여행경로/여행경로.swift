import Foundation

func solution(_ tickets:[[String]]) -> [String] {
    var answer:[String] = [] // 정답
    // 방문리스트 초기화
    var visited = Array(repeating: false, count: tickets.count)
    // 만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 
    var tickets = tickets.sorted { $0[1] < $1[1] }
    
    // 깊이우선탐색으로 해결해야함
    // 현재에서 -> 이동 가능한 목적지를 만나면 호출
    // 다 돌았다면 탈출해주도록 코드를 작성하면 됌
    // 즉 dfs로 순열을 작성하듯이 풀이하면 해결할 수 있음
    func DFS(_ cur:String, _ path: [String]) {
        // 답이 나온 경우
        if answer.count != 0 {
            return
        }
        
        // 현재 위치에서 더 돌아다닐 곳이 없다면
        if  answer.count == 0 && path.count == tickets.count + 1 {
            // 첫 번째로 도착한 path가 정답
            answer = path
            return // 탈출
        }
        
        // 매개변수는 let이므로
        var path = path
        
        // 하나씩 확인
        for i in 0..<tickets.count {
            let start = tickets[i][0] // 출발지
            let next = tickets[i][1] // 다음 행성지
            
            // 미방문이고 현재 진행할 수 있다면
            if !visited[i] && cur == start {
                visited[i] = true
                path.append(next) // 추가
               
                DFS(next, path) // 다음 진행을 위해 호출
               
                // 다른 케이스를 위해
                path.removeLast()
                visited[i] = false
            }
        }
    }
    
    DFS("ICN", ["ICN"]) // 첫 출발지는 ICN이므로 시작
    return answer
}