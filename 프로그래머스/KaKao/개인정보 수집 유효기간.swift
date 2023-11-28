// 2023 KAKAO BLIND RECRUITMENT 개인정보 수집 유효기간
// https://school.programmers.co.kr/learn/courses/30/lessons/150370
import Foundation

func solution(_ today:String, _ terms:[String], _ privacies:[String]) -> [Int] {
    var answer: [Int] = []
    let intToday = getIntegerTotalDay(today)
    let termsDic = translateTermsForDictionay(terms)
    
    for i in 0..<privacies.count {
        let splitedPrivacy = privacies[i].components(separatedBy: " ")
        let currentInfo = getIntegerTotalDay(splitedPrivacy[0])
        let termType = termsDic[splitedPrivacy[1]]!
        
        if intToday >= currentInfo + termType {
            answer.append(i+1)
        }
    }
    return answer
}

func getIntegerTotalDay(_ day: String) -> Int {
    let splitedDay = day.components(separatedBy: ".")
    return Int(splitedDay[0])! * 12 * 28 + Int(splitedDay[1])! * 28 + Int(splitedDay[2])!
}

func translateTermsForDictionay(_ terms:[String]) -> [String:Int] {
    var ret:[String:Int] = [:]
    
    for term in terms {
        let splitedTerms = term.components(separatedBy: " ")
        ret[splitedTerms[0]] = Int(splitedTerms[1])! * 28 
    }
    
    return ret
}