// 2018 KAKAO BLIND RECRUITMENT [3차] n진수 게임

func solution(_ n:Int, _ t:Int, _ m:Int, _ p:Int) -> String {
    var answer:String = ""
    var number:Int = 0
    var myIdx:Int = 1
    // 0, 1, 1, 0, 1, 1, 1, 0, 0
    while answer.count < t {
        for num in String(number, radix:n, uppercase: true) {
            if myIdx == p { // 내 차례가 되면
                answer += String(num)
            }
            
            if myIdx == m {
                myIdx = 0
            }
            
            if answer.count == t {
                break
            }
            
            myIdx += 1
        }
        number += 1
    }
    
    return answer
}