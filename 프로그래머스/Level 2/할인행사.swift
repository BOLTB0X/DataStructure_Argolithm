// https://school.programmers.co.kr/learn/courses/30/lessons/131127?language=swift
import Foundation

func solution(_ want:[String], _ number:[Int], _ discount:[String]) -> Int {
    var answer:Int = 0
    // 정현이가 원하는 제품이 바나나 3개, 사과 2개, 쌀 2개, 돼지고기 2개, 냄비 1개
    // YZ 마트에서 15일간 회원을 대상으로 할인하는 제품이 날짜 순서대로 
    // 치킨, 사과, 사과, 바나나, 쌀, 사과, 돼지고기, 바나나, 돼지고기, 쌀, 냄비, 바나나, 사과, 바나나
    var wantedDic: [String:Int] = [:]
    
    for i in 0..<want.count {
        wantedDic[want[i]] = number[i]
    }
    
    for i in 0...discount.count-10 {
        var tmpDic = wantedDic
        //print("실행: \(i)")
        for j in i..<i+10 {
            if let value = tmpDic[discount[j]] {
                if value == 0 {
                    continue
                }
                tmpDic[discount[j]]? -= 1
            }
        }
        let restValue = tmpDic.reduce(0) { $0+$1.value }
        
        if restValue == 0 {
            //print(tmpDic)
            answer += 1
            //print("됌: \(i)")
        }
    }
    return answer
}