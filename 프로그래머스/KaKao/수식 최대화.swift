// 2020 카카오 인턴십 수식 최대화
import Foundation

var perArr:[[String]] = []

func solution(_ expression:String) -> Int64 {
    var answer:Int = 0
    let numberArr = makeNumberArr(expArr: expression.map { String($0) })
    //print(numberArr)
    permutation(arr: ["+", "-", "*"], visited: [false, false, false], per: [], depth: 0)
    //print(perArr)
    
    for per in perArr {
        print(numberArr)
    }
    return Int64(answer)
}

func makeNumberArr(expArr: [String]) -> [String] {
    var numberArr:[String] = []

    var tmp:String = ""
    for e in expArr {
        if ["+", "-", "*"].contains(e) {
            numberArr.append(tmp)
            numberArr.append(e)
            tmp = ""
        } else {
            tmp += e
        }
    }
    
    if tmp.count > 0 {
        numberArr.append(tmp)
    }
    
    return numberArr
}

func permutation(arr:[String], visited:[Bool], per:[String], depth:Int) {
    if depth == arr.count {
        perArr.append(per)
        return
    }
    
    var visited = visited
    
    for i in 0..<arr.count {
        if visited[i] {
            continue
        }
        visited[i] = true
        permutation(arr:arr, visited: visited ,per: per+[arr[i]], depth: depth+1)
        visited[i] = false
    }
    return
}

func calculateOp(per: [String], numberArr:[String]) -> Int {
    var ret:Int = 0
    var numberArr = numberArr
    
    for p in per {
        var tmp:[String] = []
        
        while numberArr.count > 0 {
            let ele = numberArr.first!
            number
        }
    }
    
    return ret
}