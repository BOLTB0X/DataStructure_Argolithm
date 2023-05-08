import Foundation

func solution(_ citations:[Int]) -> Int {
    var answer: Int = 0 // 정답
    // 오름차순 정렬
    var _citations = citations.sorted(by: >) 
    
    // hidx를 판단하기 위해서 제일 먼저 배열의 값을 보고
    // 카운트를 하다 같아지거나 초과할 경우에 멈춰야함
    for i in 0..<_citations.count {
        if _citations[i] > answer {
            answer += 1
        } else {
            break;
        }
    }
    return answer
}