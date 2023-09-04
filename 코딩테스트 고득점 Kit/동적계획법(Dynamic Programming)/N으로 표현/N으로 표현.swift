import Foundation

func solution(_ N:Int, _ number:Int) -> Int {
    var answer:Int = 9
    var numbers:[Int: Int] = [:]
    
    func DFS(_ total: Int, _ target: Int, _ depth: Int) {
        if depth >= answer {
            return
        }
        
        if total == target {
            answer = depth
            return
        }
        
        for (key, value) in numbers {
            DFS(total+key, target, depth+value)
            DFS(total-key, target, depth+value)
            DFS(total/key, target, depth+value)
            DFS(total*key, target, depth+value)
        }
        return
    }
    
    numbers[1] = 2
    numbers[N] = 1
    numbers[11] = 3
    numbers[11*N] = 2
    numbers[111] = 4
    numbers[111*N] = 3
    numbers[1111] = 5
    numbers[1111*N] = 4
    numbers[11111] = 6
    numbers[11111*N] = 5
    
    DFS(0, number, 0)
    answer = answer == 9 ? -1 : answer
    return answer
}