// 2021 카카오 채용연계형 인턴십 숫자 문자열과 영단어
import Foundation

func solution(_ s:String) -> Int {
    var answer:String = "" // 정답
    var s = s // 편의용
    
    // 딕셔너리
    let numbers:[String:String] = ["zero" : "0", "one" : "1", "two" : "2", "three" : "3", "four" : "4", "five" : "5", "six" : "6", "seven" : "7", "eight" : "8", "nine" : "9"]
    var tmp:String = "" // 단어 확인용 임시 문자열 변수
    
    // 그냥 for문으로 하나씩 확인
    for i in s.indices {
        // 정수이면 바로 넣어 줌
        if s[i] >= "0" && s[i] <= "9" {
            answer.append(s[i])
        } else { // 어떤 단어인지 확인해야하는 경우
            tmp.append(s[i])
            // tmp가 길이가 3이상이면
            // 딕셔너리에 있는지 체크
            if numbers[tmp] != nil {
                // 삽입
                answer.append(numbers[tmp]!)
                // 단어가 넣어졌으므로 임시변수 초기화
                tmp = ""
            }
        }
    } 
    return Int(answer)!
}