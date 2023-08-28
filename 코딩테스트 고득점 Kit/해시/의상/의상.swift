import Foundation

func solution(_ clothes:[[String]]) -> Int {
    var answer: Int = 1 // 일단 아무것도 않 입는 수
    var dic:[String: Int] = [:]
    
    // 딕셔너리로 중복 되는 종류를 체크 후
    // 의상의 개수가 A, B, C 라면 -> 전체 조합의 개수는 (A+1) * (B+1) * (C+1) - 1 
    for clothe in clothes {
        if let _ = dic[clothe[1]] {
            dic[clothe[1]]! += 1
        } else {
            dic[clothe[1]] = 1
        }
    }
    
    // print(dic)
    for (key, value) in dic {
        answer *= (value+1)
    }
    
    return answer-1
}