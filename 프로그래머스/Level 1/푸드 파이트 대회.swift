// https://school.programmers.co.kr/learn/courses/30/lessons/134240?language=swift
import Foundation

func solution(_ food:[Int]) -> String {
    var tmp:String = ""
    
    for i in 1..<food.count {
        tmp += stringMul(String(i), food[i] / 2)
    }
    //print(tmp)
    return tmp + "0" + tmp.reversed()
}

func stringMul(_ str: String, _ n: Int) -> String {
    var ret:String = ""
    
    for i in 0..<n {
        ret += str
    }
    return ret
}