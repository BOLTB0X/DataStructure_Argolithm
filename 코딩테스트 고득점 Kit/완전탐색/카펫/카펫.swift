import Foundation

func solution(_ brown:Int, _ yellow:Int) -> [Int] {
    var answer:[Int] = [0,0]
    let tot = brown+yellow // 이게 곧 사각형의 넓이

    for i in 1...tot { // 완전탐색
        if tot % i == 0 { // 나눠떨어지면
            answer[0] = tot / i
            answer[1] = i
        }
        // 격자판 특성상 2칸을 공유함
        // 그러므로 빼고 yellow랑 같다면
        if (answer[0] - 2) * (answer[1] - 2) == yellow {
            break // 찾은거임
        }
    }
    return answer
}