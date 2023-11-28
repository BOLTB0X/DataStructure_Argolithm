// 2020 카카오 인턴십 키패드 누르기
// https://school.programmers.co.kr/learn/courses/30/lessons/67256
import Foundation

func solution(_ numbers:[Int], _ hand:String) -> String {
    var answer:String = ""
    let padPos:[(x:Int, y:Int)] = [(x:4,y:2),(x:1,y:1),(x:1,y:2),(x:1,y:3),
                                  (x:2,y:1),(x:2,y:2),(x:2,y:3),(x:3,y:1),
                                  (x:3,y:2),(x:3,y:3)]
    
    var currentLeft:(x:Int, y:Int) = (x:4,y:1) // *
    var currentRight:(x:Int, y:Int) = (x:4,y:3) // #
    
    numbers.forEach { 
        if $0 == 1 || $0 == 4 || $0 == 7 {
            answer.append("L")
            currentLeft = padPos[$0]
        } else if  $0 == 3 || $0 == 6 || $0 == 9 {
            answer.append("R")
            currentRight = padPos[$0]
        } else {
            let lDist = calculateDist(currentLeft, padPos[$0])
            let rDist = calculateDist(currentRight, padPos[$0])
            if lDist > rDist {
                answer.append("R")
                currentRight = padPos[$0]
            } else if lDist < rDist {
                answer.append("L")
                currentLeft = padPos[$0]
            } else {
                if hand == "left" {
                    answer.append("L")
                    currentLeft = padPos[$0]
                } else {
                    answer.append("R")
                    currentRight = padPos[$0]
                }
            }
        }
    }
    return answer
}

func calculateDist(_ hand:(x:Int, y:Int), _ number:(x:Int, y:Int)) -> Int {
    abs(hand.x-number.x) + abs(hand.y-number.y)
}