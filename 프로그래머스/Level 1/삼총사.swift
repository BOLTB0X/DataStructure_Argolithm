// https://school.programmers.co.kr/learn/courses/30/lessons/131705
import Foundation

func solution(_ number:[Int]) -> Int {
    var answer:Int = 0
    var comArr:[[Int]] = []
    
    func combination(_ arr: [Int], _ cur: Int, _ depth: Int) {
        if depth == 3 {
            comArr.append(arr)
            return
        }
        
        for i in cur..<number.count {
            combination(arr+[number[i]], i+1, depth+1)
        }
    }
    
    combination([], 0, 0)
    
    for com in comArr {
        if com.reduce(0) {$0 + $1} == 0 {
            answer += 1
        }
    }
    return answer
}