// 2023 KAKAO BLIND RECRUITMENT 이모티콘 할인행사
// https://school.programmers.co.kr/learn/courses/30/lessons/150368
import Foundation

func permutation(_ arr: [Int], _ limit: Int) -> [[Int]] {
    var ret: [[Int]] = []
    
    func DFS(_ per: [Int], _ depth: Int) {
        if depth == limit {
            ret.append(per)
            return
        }
    
        for i in 0..<arr.count {
            DFS(per + [arr[i]], depth + 1)
        }
    }
    
    DFS([], 0)
    return ret
}

func getPlusServies(_ discount: [Int], _ users: [[Int]], _ emoticons: [Int]) -> (Int, Int) {
    var applyCount = 0
    var totalMoney = 0
    
    for user in users {
        var emoticonsTotal = 0
        
        for i in 0..<emoticons.count {
            if user[0] <= discount[i] {
                let prices = emoticons[i] - (emoticons[i] / 100 * discount[i])
                emoticonsTotal += prices
            }
            
            if user[1] <= emoticonsTotal {
                applyCount += 1
                emoticonsTotal = 0
                break
            }
        }
        
        totalMoney += emoticonsTotal
    }
    
    return (applyCount, totalMoney)
}

func solution(_ users:[[Int]], _ emoticons:[Int]) -> [Int] {
    var answer: [Int] = [0, 0]
    let discountPermutation = permutation([10, 20, 30, 40], emoticons.count)
    
    for discount in discountPermutation {
        let result: (applyCount: Int, totalMoney: Int) = getPlusServies(discount, users, emoticons)
        
        if  answer[0] <= result.applyCount {
            if answer[0] < result.applyCount {
                answer[0] = result.applyCount
                answer[1] = result.totalMoney
            } else {
                answer[1] = max(answer[1], result.totalMoney)
            }
        }
    }
    
    return answer
}