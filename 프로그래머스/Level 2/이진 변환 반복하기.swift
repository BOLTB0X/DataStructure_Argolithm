// https://school.programmers.co.kr/learn/courses/30/lessons/70129?language=swift
import Foundation

func solution(_ s:String) -> [Int] {
    var answer:[Int] = [0,0]
    var s = s
    
    func removeZero(_ x: [String]) -> [String] {
        var ret:[String] = []
        
        for i in 0..<x.count {
            if x[i] != "0" {
                ret.append(x[i])
            } else {
                answer[1] += 1
            }
        }
        
        return ret
    }
    
    func getBinaryNumber(_ c: Int) -> [String] {
        var ret:[String] = []
        var number:Int = c
        
        while number > 0 {
            ret.append(String(number%2))
            number /= 2
        }
        
        return ret.reversed()
    }
    
    
    while true {
        if s == "1" {
            break
        }
        answer[0] += 1
        
        let removedZero = removeZero(s.map {String($0)})
        s = getBinaryNumber(removedZero.count).joined()
    }
    
    return answer
}