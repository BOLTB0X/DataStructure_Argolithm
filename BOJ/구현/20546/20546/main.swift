//
//  main.swift
//  20546 기적의 매매법
//  https://www.acmicpc.net/problem/20546
//  Created by KyungHeon Lee on 2023/09/05.
//

import Foundation

let N = Int(readLine()!)!
let budgetList = readLine()!.split(separator: " ").map { Int(String($0))! }

print(solution(N, budgetList))

func solution(_ N: Int, _ budgetList: [Int]) -> String {
    var answer: String = ""
    var moneys = [N, N]
    var budgets = [0, 0]
    
    // 준현이는 주식을 살 수 있다면 무조건 최대한 많이
    // 성민이
    // 현재 가지고 있는 현금이 100원이고 주가가 11원이라면 99원어치의 주식을 매수하는 것이다. 단, 현금이 100원 있고 주가가 101원이라면 주식을 살 수 없다. 성민이는 빚을 내서 주식을 하지는 않는다.
    // 3일 연속 가격이 전일 대비 상승하는 주식은 다음날 무조건 가격이 하락한다고 가정한다. 따라서 현재 소유한 주식의 가격이 3일째 상승한다면, 전량 매도한다. 전일과 오늘의 주가가 동일하다면 가격이 상승한 것이 아니다.
    // 3일 연속 가격이 전일 대비 하락하는 주식은 다음날 무조건 가격이 상승한다고 가정한다. 따라서 이러한 경향이 나타나면 즉시 주식을 전량 매수한다. 전일과 오늘의 주가가 동일하다면 가격이 하락한 것이 아니다.
    
    // 1월 14일의 자산은 (현금 + 1월 14일의 주가 × 주식 수)로 계산
    
    for i in 0..<budgetList.count {
        if budgetList[i] <= moneys[0] { // 준현이는 최대한 많이 삼
            budgets[0] += moneys[0]/budgetList[i]
            moneys[0] = moneys[0]%budgetList[i]
        }
        
        if i >= 3 { // 성민이
            if budgetList[i-1] < budgetList[i-2] && budgetList[i-2] < budgetList[i-3] { // 하락세
                if budgetList[i] <= moneys[1] {
                    budgets[1] += moneys[1]/budgetList[i]
                    moneys[1] = moneys[1]%budgetList[i]
                }
            } else if budgets[1] > 0 && budgetList[i-1] > budgetList[i-2] && budgetList[i-2] > budgetList[i-3] {
                moneys[1] += budgetList[i] * budgets[1]
                budgets[1] = 0
            }
        }
    }
    
    let jScore = moneys[0]+(budgetList.last!*budgets[0])
    let sScore = moneys[1]+(budgetList.last!*budgets[1])
    
    if jScore > sScore {
        answer = "BNP"
    } else if jScore < sScore {
        answer = "TIMING"
    } else {
        answer = "SAMESAME"
    }
    return answer
}
