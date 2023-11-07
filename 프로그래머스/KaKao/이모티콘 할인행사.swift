// 2023 KAKAO BLIND RECRUITMENT 이모티콘 할인행사
// https://school.programmers.co.kr/learn/courses/30/lessons/150368
import Foundation

func solution(_ users:[[Int]], _ emoticons:[Int]) -> [Int] {
    var answer: [Int] = [0, 0]
    var per: [[Int]] = []
        
    func permutation(_ discount: [Int], _ p: [Int], _ depth: Int, _ limit: Int) {
        if limit == depth {
            per.append(p)
            return
        }
        
        for d in discount {
            permutation(discount, p + [d], depth + 1, limit);
        }
    }
    
    permutation([10, 20, 30, 40], [], 0, emoticons.count);
    
    for p in per {
        var plusJoinCount = 0
        var totalCost = 0
        
        for user in users {
            var cost = 0
            for i in 0..<emoticons.count {
                if user[0] <= p[i] {
                    cost += (emoticons[i] - (emoticons[i] / 100) * p[i])
                }
                
                if user[1] <= cost { // 가입자 발견
                    break;
                }
            }
            
            if user[1] <= cost {
                plusJoinCount += 1
                cost = 0
            }
            totalCost += cost
        }
        
        if answer[0] < plusJoinCount {
            answer[0] = plusJoinCount
            answer[1] = totalCost
        } else if answer[0] == plusJoinCount {
            answer[1] = max(answer[1], totalCost)
        }
    }

    return answer
}