import Foundation

func solution(_ participant: [String], _ completion: [String]) -> String{
    var answer:String = ""
    var dict:[String:Int] = [:] // 사용할 딕셔너리
    
    // 참가자륵 딕셔너리에 넣어줌
    for p in participant {
        // 있다면
        if let _ = dict[p] {
            dict[p] = dict[p]! + 1 // 카운트
        } else { // 딕셔너리의 key중에 없다면
            dict[p] = 1
        }
    }
    
    // 이제 완주를 위 방식처럼 빼주면 그만
    for c in completion {
        dict[c] = dict[c]! - 1
    }
    
    // 딕셔너리 value 기준으로 오름차순 정렬
    let arr = dict.sorted(by: {$0.value < $1.value})
    answer = arr.last!.key
    return answer
}

let participant1 = ["leo", "kiki", "eden"]
let participant2 = ["marina", "josipa", "nikola", "vinko", "filipa"]
let participant3 = ["mislav", "stanko", "mislav", "ana"]

let completion1 = ["eden", "kiki"]
let completion2 = ["josipa", "filipa", "marina", "nikola"]
let completion3 = ["stanko", "ana", "mislav"]

print(solution(participant1, completion1))
print(solution(participant2, completion2))
print(solution(participant3, completion3))
