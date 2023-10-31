// https://school.programmers.co.kr/learn/courses/30/lessons/178870
import Foundation

func solution(_ sequence:[Int], _ k:Int) -> [Int] {
    var answer: [Int] = []
    var l = 0
    var r = 0
    var tot = sequence[r]
    var maxDiff = 1000001
    
    while (l < sequence.count && r < sequence.count) {        
        if tot > k { // 왼쪽
            tot -= sequence[l]
            if l + 1 >= sequence.count { break }
            l += 1
            
        } else { // 오른쪽
            if tot == k &&  maxDiff > r - l {
                answer = [l, r]
                maxDiff = r - l
            }
            
            if r + 1 >= sequence.count { break } // 범위 확인
            r += 1
            tot += sequence[r] // illegal instruction (core dumped)?
        }
    }
    return answer
}