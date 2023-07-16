// 2019 KAKAO BLIND RECRUITMENT 오픈채팅방
import Foundation

func solution(_ record:[String]) -> [String] {
    var answer:[String] = []
    var usersDict: [String:String] = [:] // 아이디 : 닉네임 
    
    for r in record { // 나중에 닉변경한걸 반영하기 위해
        let rArr = r.split(separator: " ").map { String($0) }
        if rArr.count > 2 {
            usersDict[rArr[1]] = rArr[2]
        }
    }
    //print(usersDict)
    
    for r in record { 
        let rArr = r.split(separator: " ").map { String($0) }
        
        if rArr[0] == "Enter" {
            answer.append("\(usersDict[rArr[1]]!)님이 들어왔습니다.")
        } else if rArr[0] == "Leave" {
            answer.append("\(usersDict[rArr[1]]!)님이 나갔습니다.")
        }
    }

    return answer
}