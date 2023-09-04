import Foundation

func solution(_ tickets:[[String]]) -> [String] {
    var answer:[String] = [] 
    var visited = Array(repeating: false, count: tickets.count)
    var tickets = tickets.sorted { $0[1] < $1[1] }

    func DFS(_ cur:String, _ path: [String]) {
        if answer.count != 0 {
            return
        }
        
        if  answer.count == 0 && path.count == tickets.count + 1 {
            answer = path
            return 
        }
        
        var path = path
        
        for i in 0..<tickets.count {
            let start = tickets[i][0]
            let next = tickets[i][1]
            
            if !visited[i] && cur == start {
                visited[i] = true
                path.append(next) 

                DFS(next, path) 

                path.removeLast()
                visited[i] = false
            }
        }
    }
    
    DFS("ICN", ["ICN"])

    return answer
}