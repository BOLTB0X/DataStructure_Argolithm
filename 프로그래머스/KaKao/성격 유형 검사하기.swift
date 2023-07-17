// 2022 KAKAO TECH INTERNSHIP 성격 유형 검사하기
import Foundation

func solution(_ survey:[String], _ choices:[Int]) -> String {
    var answer:String = ""
    var choicesSocre: [Int] = [0,3,2,1,0,1,2,3]
    var jipyo = ["R": 0, "T": 0, "C": 0, "F": 0, "J": 0, "M": 0, "A": 0, "N": 0]
    
    for (i, sur) in survey.enumerated() {
        let tmp = sur.map{String($0)}
        
        if choices[i] > 4 {
            jipyo[tmp[1]]! += choicesSocre[choices[i]]
        } else if choices[i] < 4 {
            jipyo[tmp[0]]! += choicesSocre[choices[i]]
        } else {
            continue
        }
    }
    
    //print(jipyo)
    for key in ["RT", "CF", "JM", "AN"] {
        let front = String(key.first!)
        let back = String(key.last!)
        
        if jipyo[front]! < jipyo[back]! {
            answer += back
        } else {
            answer += front
        }
    }
    return answer
}