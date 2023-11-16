// 2022 KAKAO BLIND RECRUITMENT k진수에서 소수 개수 구하기
// https://school.programmers.co.kr/learn/courses/30/lessons/92335
import Foundation

func getKnumber(_ n: Int, _ k: Int) -> [String] {
    var ret: [String] = []
    var number = n
    
    while number > 0 {
        ret.append(String(number % k))
        number /= k
    }
    
    return ret.reversed()
}

func isPrimeNumber(_ number: Int) -> Bool {
    if number < 2 { return false }
    
    for i in 2..<Int(sqrt(Double(number))+1) {
        if number % i == 0 { return false }
    }
    return true
}

func solution(_ n:Int, _ k:Int) -> Int {
    var answer: Int = 0
    let kNumber = getKnumber(n, k)
    var tmp: String = ""
    
    for number in kNumber {
        if number == "0" {
            if tmp == "" { continue }
            
            if isPrimeNumber(Int(tmp)!) { 
                answer += 1
            }
            tmp = ""
        } else {
            tmp += number
        }
    }
    
    if tmp.count > 0 && isPrimeNumber(Int(tmp)!) { 
        answer += 1
    }
    
    return answer
}