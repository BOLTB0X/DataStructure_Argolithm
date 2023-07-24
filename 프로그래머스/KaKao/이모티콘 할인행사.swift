// 2023 KAKAO BLIND RECRUITMENT 이모티콘 할인행사
import Foundation

var maxCnt:Int = 0
var maxTotalMoney:Int = 0
var per:[[Int]] = []

func solution(_ users:[[Int]], _ emoticons:[Int]) -> [Int] {
    DFS([10,20,30,40], [], emoticons.count, 0) // 중복순열 생성
    //print(per)
    
    for p in per {
        calculateEmoticons(users, emoticons, p)
    }

    return [maxCnt, maxTotalMoney]
}

func DFS(_ discount:[Int], _ arr:[Int], _ limit:Int, _ depth:Int) {
    if limit == depth {
        per.append(arr)
        return
    }
    
    for d in discount {
        DFS(discount, arr + [d], limit, depth+1)
    }
    return
}

func calculateEmoticons(_ users:[[Int]], _ emoticons:[Int], _ per:[Int]) {
    var cnt:Int = 0
    var totMoney:Int = 0
    
    for user in users {
        var tot:Int = 0
        for i in 0..<emoticons.count {
            if user[0] <= per[i] { 
                tot += (emoticons[i] - ((emoticons[i] / 100) * per[i]))
            } 

            if tot >= user[1] {
                break
            }
        }
        
        //print(tot)
        
        if tot >= user[1] {
            cnt += 1
            tot = 0
        }
        totMoney += tot
    }
    
    if cnt >= maxCnt {
        if cnt == maxCnt {
            maxTotalMoney = max(maxTotalMoney, totMoney)
        } else {
            maxTotalMoney = totMoney
        }
        maxCnt = cnt
    }
    
    return
}