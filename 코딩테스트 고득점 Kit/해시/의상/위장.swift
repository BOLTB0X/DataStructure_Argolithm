import Foundation

func solution(_ clothes:[[String]]) -> Int {
    var answer: Int = 1 // 정답
    var dict:[String: Int] = [:] // 딕셔너리 선언
    
    // 딕셔너리로 중복 되는 종류를 체크 후
    // 의상의 개수가 A, B, C 라면 -> 전체 조합의 개수는 (A+1) * (B+1) * (C+1) - 1 
    
    // clothea를 돌면서 딕셔너리에 넣어 줌
    for c in clothes {
        // 현재 딕셔너리에 옷 종류가 없다면
        if dict.keys.contains(c[1]) == false {
            dict[c[1]] = 1 // 만들어줌
        } else { // 이미 있다면
            dict[c[1]]? += 1
        }
    }
    
    // 앞에 적어둔 대로
    // 공식 이용
    for (key, value) in dict {
        answer *= (value+1)
    }
    
    return answer-1
}