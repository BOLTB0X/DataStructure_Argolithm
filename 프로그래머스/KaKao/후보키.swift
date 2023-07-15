// 2019 KAKAO BLIND RECRUITMENT 후보키
import Foundation

var comArr:[[Int]] = []

func solution(_ relation:[[String]]) -> Int {
    var answer:[Set<Int>] = []
    
    for i in 1...relation[0].count {
        combination(Array(0..<relation[0].count), [], i, 0, 0)
    }
    
    for com in comArr {
        var res: Set<String> = makeKey(com, relation) 
        
        if res.count == relation.count { // 유일성 확인
            var flag: Bool = true
            for a in answer { // 최소성 확인
                if a.isSubset(of: com) {  
                    flag = false
                    break
                }
            }
            if flag {
                answer.append(Set(com))
            }
        }
    }

    //print(answer)
    return answer.count
}

func combination(_ arr: [Int],  _ com:[Int], _ size: Int, _ cur: Int, _ level: Int){
    if size == level {
        comArr.append(com)
        return
    }
    
    var com = com
    for i in cur..<arr.count {
        com.append(i)
        combination(arr, com, size, i + 1, level+1)
        com.removeLast()
    }
}

func makeKey(_ com:[Int], _ relation:[[String]]) -> Set<String>{
    var res: Set<String> = []
    
    for row in relation {
        let key = com.reduce(""){ return $0 + row[$1] }
        res.insert(key)
    }
    
    return res
}