import Foundation

func solution(participant: [String], completion: [String]) -> String{
    var answer: String = ""
    var dict: [String:Int] = [:]

    for p in participant{
        // 참가중 있다면
        // 새로운 표현 습득
        if let _ = dict[p] {
            dict[p] = dict[p]! + 1
        }else{ // 없는 경우
            dict[p] = 1
        }
    }
    
    // 완주자들 체크
    for c in completion{
        dict[c] = dict[c]! - 1
    }
    
    let arr = dict.sorted(by: {$0.value < $1.value })
    answer = arr.last!.key
    return answer
}