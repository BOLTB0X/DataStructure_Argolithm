// 2019 카카오 개발자 겨울 인턴십 징검다리 건너기
// https://school.programmers.co.kr/learn/courses/30/lessons/64062
import Foundation

func solution(_ stones:[Int], _ k:Int) -> Int {
    var answer:Int = 0
    var start = stones.min()!
    var end = stones.max()!
    
    while start <= end {
        let mid = (start+end) / 2
        let maxJumpCount = jumpedMaxFriendCount(stones, k, mid)
        
        if maxJumpCount < k {
            answer = max(answer, mid)
            start = mid + 1
        } else {
            end = mid - 1
        }
    }
    
    return answer
}

func jumpedMaxFriendCount(_ stones:[Int], _ k:Int, _ friendCount: Int) -> Int {
    var ret: Int = 0
    var jumpCount : Int = 0
    var stones = stones
    
    for i in 0..<stones.count {
        stones[i] -= friendCount
            
        if stones[i] < 0 { jumpCount += 1}
        else {
            ret = max(ret, jumpCount)
            jumpCount = 0
        }
    }
    
    ret = max(ret, jumpCount)
        
    return ret
}