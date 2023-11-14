// 2022 KAKAO TECH INTERNSHIP 성격 유형 검사하기
import Foundation

func solution(_ survey:[String], _ choices:[Int]) -> String {
    var answer: String = ""
    var jipyoType: [Character: Int] = ["R": 0, "T": 0,
                                      "C": 0, "F": 0,
                                      "J": 0, "M": 0,
                                      "A": 0, "N": 0]
    let scores: [Int] = [0, 3, 2, 1, 0, 1, 2, 3]
    
    for i in 0..<survey.count {
       if choices[i] < 4 {
           jipyoType[survey[i].first!]! += scores[choices[i]]
       } else {
           jipyoType[survey[i].last!]! += scores[choices[i]]
       }
    }
    
    //print(jipyoType)
    for type in ["RT", "CF", "JM", "AN"] {
        if jipyoType[type.first!]! >= jipyoType[type.last!]! {
            answer.append(type.first!)
        } else {
            answer.append(type.last!)
        }
    }
    return answer
}