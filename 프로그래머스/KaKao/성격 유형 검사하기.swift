// 2022 KAKAO TECH INTERNSHIP 성격 유형 검사하기
// https://school.programmers.co.kr/learn/courses/30/lessons/118666
import Foundation

func solution(_ survey:[String], _ choices:[Int]) -> String {
    var answer: String = ""
    var personalityTypesScore: [Character:Int] = ["R": 0, "T": 0, "C": 0, "F":0,
                                                  "J": 0, "M" : 0, "A":0, "N":0]
    let personalityTypesArr = ["RT", "CF", "JM", "AN"]
    let choiceScores = [0, 3, 2, 1, 0, 1, 2, 3]
    
    for i in 0..<choices.count {
        if choices[i] < 5 {
            personalityTypesScore[survey[i].first!]! += choiceScores[choices[i]]
        } else {
            personalityTypesScore[survey[i].last!]! += choiceScores[choices[i]]
        }
    }
    
    //print(personalityTypesDic)
    
    for p in personalityTypesArr {
        let type1 = p.first!
        let type2 = p.last!
        
        if personalityTypesScore[type1]! < personalityTypesScore[type2]! {
            answer.append(type2)
        } else {
            answer.append(type1)
        }
    }
    
    return answer
}