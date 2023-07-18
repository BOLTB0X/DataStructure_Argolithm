// 2022 KAKAO BLIND RECRUITMENT k진수에서 소수 개수 구하기
import Foundation

func solution(_ n:Int, _ k:Int) -> Int {
    var answer:Int = 0
    var tmp:String = ""
    //print(transK(n, k))
    let newNumber = transK(n, k)
    
    for (i, value) in newNumber.enumerated() {
        if value == "0" {
            if tmp.count == 0 {
                continue
            }
            
            if isPrime(Int(tmp)!) {
                answer += 1
            }
            tmp = ""
        } else {
            tmp += value
        }
    }
    
    if tmp.count > 0 && isPrime(Int(tmp)!) {
        answer += 1 
    }
    return answer
}

func transK(_ number: Int, _ k: Int) -> [String] {
    var ret:[String] = []
    var number = number
        
    while number > 0 {
        ret.append(String(number % k))
        number /= k
    }
    
    //print(ret)
    return ret.reversed()
}

func isPrime(_ number: Int) -> Bool {
    if number < 2 {
        return false
    }
    
    for i in 2..<Int(sqrt(Double(number)) + 1) {
        if number % i == 0 {
            return false
        }
    }
    
    return true
}