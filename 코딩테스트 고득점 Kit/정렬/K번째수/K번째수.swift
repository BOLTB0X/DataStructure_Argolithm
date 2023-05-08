import Foundation

func solution(_ array:[Int], _ commands:[[Int]]) -> [Int] {
    var answer : [Int] = []
    
    for command in commands {
        // 해당 조건에 따른 임시 배열 
        var tmp = array[command[0]-1...command[1]-1]
        tmp.sort() // 자른 후 정렬
        let tmpArr = Array(tmp) // 배열형이 다르므로 
        answer.append(Int(tmpArr[command[2] - 1]))
    }
    return answer
}