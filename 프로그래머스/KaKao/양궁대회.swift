// 2022 KAKAO BLIND RECRUITMENT 양궁대회
import Foundation

var comArr:[[Int]] = []

func solution(_ n:Int, _ info:[Int]) -> [Int] {
    var answer:[Int] = [-1]
    var maxDiff:Int = -1
    
    combination(arr:[0,1,2,3,4,5,6,7,8,9,10], com:[], r: n, cur:0, depth:0)
    
    for com in comArr {
        var scoreArr = Array(repeating: 0, count: 11)
        for c in com {
            scoreArr[10-c] += 1
        }
        
        var lastScore = calculateScore(lion:scoreArr, aporch: info)
        
        if lastScore[0] > lastScore[1] && maxDiff < (lastScore[0] - lastScore[1]) {
            answer = scoreArr
            maxDiff = lastScore[0] - lastScore[1]
        }
    }
    return answer
}

func combination(arr:[Int], com:[Int], r:Int, cur:Int, depth:Int) {
    if depth == r {
        var com = com
        comArr.append(com)
        return
    }
    
    for i in cur..<arr.count {
        combination(arr: arr, com: com+[arr[i]], r: r, cur:i, depth: depth+1)
    }
    return
}

func calculateScore(lion:[Int], aporch:[Int]) -> [Int] {
    var lScore:Int = 0
    var aScore:Int = 0
    
    for i in 0..<11 {
        if lion[i] == 0 && aporch[i] == 0 {
            continue
        }
        
        if lion[i] > aporch[i] {
            lScore += (10 - i)
        } else {
            aScore += (10 - i)
        }
    }
    
    return [lScore, aScore]
}