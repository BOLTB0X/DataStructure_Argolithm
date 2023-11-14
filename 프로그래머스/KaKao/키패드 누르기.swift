// https://school.programmers.co.kr/learn/courses/30/lessons/67256
import Foundation

func getDist(_ pos1: (Int, Int), _ pos2: (Int, Int)) -> Int {
    abs(pos1.0 - pos2.0) + abs(pos1.1 - pos2.1)
}

func solution(_ numbers:[Int], _ hand:String) -> String {
    var answer: String = ""
    var currentL: (Int, Int) = (4, 1)
    var currentR: (Int, Int) = (4, 3)
    let pad: [(Int, Int)] = [(4, 2), (1, 1), (1, 2), (1, 3),
                            (2, 1), (2, 2), (2, 3),
                            (3, 1), (3, 2), (3, 3)]
    
    for number in numbers {
        switch number {
            case 1, 4, 7:
            answer += "L"
            currentL = pad[number]
            
            case 3, 6, 9:
            answer += "R"
            currentR = pad[number]
            
            default:
            let leftToNum = getDist(pad[number], currentL)
            let rightToNum = getDist(pad[number], currentR)
            
            if leftToNum < rightToNum {
                answer += "L"
                currentL = pad[number]
            } else if leftToNum > rightToNum {
                answer += "R"
                currentR = pad[number]
            } else {
                if hand == "left" {
                    answer += "L"
                    currentL = pad[number]
                } else {
                    answer += "R"
                    currentR = pad[number]
                }
            }
        }
    }

    return answer
}