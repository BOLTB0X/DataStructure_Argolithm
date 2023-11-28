import Foundation

import Foundation

func solution(_ queue1:[Int], _ queue2:[Int]) -> Int {
    var answer: Int = 0
    
    var que1 = queue1
    var que2 = queue2
    var head1: Int = 0
    var head2: Int = 0
    
    var q1Sum = que1.reduce(0, +)
    var q2Sum = que2.reduce(0, +)
    let qSize = queue1.count * 4
    
    while head1 < qSize && head2 < qSize {
        if answer > qSize {
            answer = -1
            break
        }

        if q1Sum == q2Sum {
            break
        } else {
            if q1Sum > q2Sum {
                q1Sum -= que1[head1]
                q2Sum += que1[head1]
                que2.append(que1[head1])
                head1 += 1
            } else {
                q2Sum -= que2[head2]
                q1Sum += que2[head2]
                que1.append(que2[head2])
                head2 += 1
            }
            answer += 1
        }
    }
    
    return answer
}