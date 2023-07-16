// 2023 KAKAO BLIND RECRUITMENT 이모티콘 할인행사
import Foundation

var comArr:[[Int]] = []
var maxCnt:Int = 0
var maxValue:Int = 0

func solution(_ users:[[Int]], _ emoticons:[Int]) -> [Int] {
    var answer:[Int] = []
    // dfs를 현재 users배열의 user의 0번째 원소 보다 크거나 같은 할인을 선택하며
    // 조합을 꾸려야함
    var users = users.sorted { $0[0] > $1[0]}
    var disCount = [10, 20, 30, 40].filter({ $0 >= users.last![0] })
    
    combination(disCount: disCount, arr: [], lim: emoticons.count, cur: 0)
    
    for com in comArr {
        // 이 할인율로 가격 계산
        calaculateUsers(users, emoticons, com)
    }
    
    answer.append(maxCnt)
    answer.append(maxValue)
    return answer
}

func combination(disCount:[Int] , arr: [Int], lim: Int, cur: Int) {
    if lim == cur {
        comArr.append(arr)
        return
    }
    
    for d in disCount {
        combination(disCount: disCount, arr: arr + [d], lim: lim, cur: cur+1)
    }
    return
}

func calaculateUsers(_ users:[[Int]], _ emoticons:[Int], _ com: [Int]) {
    var cnt:Int = 0
    var value: Int = 0
    
    for user in users {        
        var tot:Int = 0
        
        for i in 0..<com.count {
            if user[0] <= com[i] { // 할인 할수 있으면     
                tot += (emoticons[i] - ((emoticons[i] / 100) * com[i]))
            }
        }
        
        if tot >= user[1] { // 가입 조건 달성
            cnt += 1
        } else {
            value += tot
        }

        //print(c)
    }
    // 모든게 종료
    if cnt > maxCnt {
        maxCnt = cnt
        maxValue = value
    } else if cnt == maxCnt {
        maxValue = max(value, maxValue)
    }
    
    //print(maxCnt, maxValue)
    return
}