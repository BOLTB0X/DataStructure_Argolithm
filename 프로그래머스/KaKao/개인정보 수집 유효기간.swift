// 2023 KAKAO BLIND RECRUITMENT 개인정보 수집 유효기간
import Foundation

func solution(_ today:String, _ terms:[String], _ privacies:[String]) -> [Int] {
    var answer:[Int] = []
    let tDic: [String: Int] = transDic(terms)
    let cToday = changeDateToDay(date: today)
    
    for (idx, privacie) in privacies.enumerated() {
        let splitedP = privacie.split(separator: " ").map{ String($0) }
        let startDay = changeDateToDay(date: splitedP[0])
        //print(cToday, startDay)
        
        if cToday >= startDay + tDic[splitedP[1]]! {
            answer.append(idx+1)
        }
        
    }
    
    return answer
}

func transDic(_ terms: [String]) -> [String:Int] {
    var ret: [String: Int] = [:]
    
    for term in terms {
        let t = term.split(separator: " ").map{String($0)}
        ret[t[0]] = Int(t[1])!*28
    }
    
    return ret
}

func changeDateToDay(date: String) -> Int {
    let splitedD = date.split(separator: ".").map{String($0)}
    
    return Int(splitedD[0])!*28*12 + Int(splitedD[1])!*28 + Int(splitedD[2])!
}