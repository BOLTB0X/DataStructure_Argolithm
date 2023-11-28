// 2021 카카오 채용연계형 인턴십 숫자 문자열과 영단어
// https://school.programmers.co.kr/learn/courses/30/lessons/81301
import Foundation

func solution(_ s:String) -> Int {
    var answer:String = ""
    let numberDict = ["zero": "0", "one": "1", "two": "2", "three": "3",
                     "four": "4", "five": "5", "six": "6", "seven": "7",
                     "eight": "8", "nine": "9"]
    var tempString:String = ""
    
    for element in s {
        if element.isNumber {
            answer.append(element)
        } else {
            tempString.append(element)
            
            if let value = numberDict[tempString] {
                answer += numberDict[tempString]!
                tempString = ""
            }
        }
    }
    
    return Int(answer)!
}