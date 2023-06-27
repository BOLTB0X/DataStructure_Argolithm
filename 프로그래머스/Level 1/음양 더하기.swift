import Foundation

func solution(_ absolutes:[Int], _ signs:[Bool]) -> Int {
    var answer = 0
    
    for i in signs.indices {
        // 삼항연산자
        answer += signs[i] == true ? absolutes[i] : -absolutes[i]
    }
    return answer
}