import Foundation

func solution(_ queue1:[Int], _ queue2:[Int]) -> Int {
    // 14 18(3 2 7 2 4) 15(2 7 2 4) 
    // 16 12(6 5 1) 1 15(6 5 1 3)
    var answer:Int = 0
    var queue1:[Int] = queue1
    var queue2:[Int] = queue2
    
    // removeFirst 이용시 시간 초과
    let cnt = queue1.count * 4
    var q1Sum = queue1.reduce(0) { $0 + $1 }
    var q1Head = 0
    var q2Sum = queue2.reduce(0) { $0 + $1 }
    var q2Head = 0

    while q1Head < cnt && q2Head < cnt {
        if answer > cnt {
            return -1
        }
        
        if q1Sum == q2Sum {
            break
        } else {
            answer += 1
            if q1Sum > q2Sum {
                queue2.append(queue1[q1Head])
                q1Sum -= queue1[q1Head]
                q2Sum += queue1[q1Head]
                q1Head += 1
            } else {
                queue1.append(queue2[q2Head])
                q1Sum += queue2[q2Head]
                q2Sum -= queue2[q2Head]
                q2Head += 1
            }
        }
    }

    return answer
}