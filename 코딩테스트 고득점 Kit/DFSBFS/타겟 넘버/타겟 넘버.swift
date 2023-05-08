import Foundation

var answer:Int = 0
var visited:[Bool] = Array(repeating: false, count: 20)

func DFS(array: [Int], aim: Int, tot: Int, level: Int) {
    // 도달했다면
    if level == array.count {
        if aim == tot { // 같다면
            answer += 1
        }
        return
    }
    
    // 더하기 빼기 둘다 진행
    DFS(array: array, aim: aim, tot: tot + array[level], level: level + 1)
    DFS(array: array, aim: aim, tot: tot - array[level], level: level + 1)
    return
}

func solution(_ numbers:[Int], _ target:Int) -> Int {
    // DFS 이용
    DFS(array: numbers, aim: target, tot:0, level: 0)
    return answer
}