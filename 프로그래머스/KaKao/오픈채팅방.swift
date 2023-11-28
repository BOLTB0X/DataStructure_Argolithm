// 2019 KAKAO BLIND RECRUITMENT 오픈채팅방
// https://school.programmers.co.kr/learn/courses/30/lessons/42888
import Foundation

func solution(_ record:[String]) -> [String] {
    var answer:[String] = []
    let idNickDict: [String: String] = makeRelationshipDictionary(record)
    
    for rec in record {
        let splitedR = rec.components(separatedBy: " ")
        if splitedR[0] == "Enter" {
            answer.append("\(idNickDict[splitedR[1]]!)님이 들어왔습니다.")
        } else if splitedR[0] == "Leave" {
            answer.append("\(idNickDict[splitedR[1]]!)님이 나갔습니다.")
        }
    }
    return answer
}

func makeRelationshipDictionary(_ record:[String]) -> [String: String] {
    var ret: [String: String] = [:]
    
    for r in record {
        let splitedR = r.components(separatedBy: " ")
        if splitedR[0] == "Leave" { continue }
        ret[splitedR[1]] = splitedR[2] 
    }
    return ret
}