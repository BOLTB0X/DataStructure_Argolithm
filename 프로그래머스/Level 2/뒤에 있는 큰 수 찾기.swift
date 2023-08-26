// https://school.programmers.co.kr/learn/courses/30/lessons/154539?language=swift
import Foundation

func solution(_ numbers:[Int]) -> [Int] {
    var answer:[Int] = Array(repeating: -1, count: numbers.count)
    var stack:[Int] = []
    
    for i in 0..<numbers.count {
        while !stack.isEmpty && numbers[stack.last!] < numbers[i] {
            answer[stack.removeLast()] = numbers[i]
        }
        stack.append(i)
    }
    return answer
}