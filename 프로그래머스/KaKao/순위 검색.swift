// # 2021 KAKAO BLIND RECRUITMENT 순위 검색
import Foundation

func solution(_ info:[String], _ query:[String]) -> [Int] {
    var answer:[Int] = []
    var comArr:[[Int]] = []
    var applyDic:[String:[Int]] = [:]
    
    func combination(arr: [Int], com: [Int], r: Int, cur: Int, depth: Int) {
        if depth == r {
            comArr.append(com)
            return
        }
        
        for i in cur..<arr.count {
            combination(arr: arr, com: com+[arr[i]], r: r, cur: i+1, depth: depth+1)
        }
        return
    }
    
    for i in 0..<5 {
        combination(arr: [0,1,2,3], com:[], r: i, cur: 0, depth: 0)
    }
    
    for com in comArr {
        for i in info {
            var splitedI = i.components(separatedBy: " ")
            
            for c in com {
                splitedI[c] = "-"
            }
            // print(splitedI)
            let dicKey = "\(splitedI[0])\(splitedI[1])\(splitedI[2])\(splitedI[3])"
            let dicVal = Int(splitedI[4])!
            if let _ = applyDic[dicKey] {
                applyDic[dicKey]?.append(dicVal)
            } else {
                applyDic[dicKey] = [dicVal]
            }
        }
    }
    
    //print(applyDic)
    for key in applyDic.keys {
        if var valueArr = applyDic[key] {
            valueArr.sort()
            applyDic[key] = valueArr
        }
    }
    //print(applyDic)
    
    for q in query {
        let rq = q.components(separatedBy: " ")
        //print(rq)
        let findKey = "\(rq[0])\(rq[2])\(rq[4])\(rq[6])"
        //print(newQ)
        let findVal = Int(rq[7])!
        
        if let valueArr = applyDic[findKey] {
            // 이분 탐색
            var low = 0
            var high = valueArr.count - 1
            var mid = 0

            while low <= high {
                mid = (low + high)/2
                if valueArr[mid] < findVal {
                    low = mid+1
                } else {
                    high = mid-1
                }
            }
            answer.append(valueArr.count - low)
        } else {
            answer.append(0)
        }
    }
    return answer
}