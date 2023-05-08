import Foundation

func solution(_ prices:[Int]) -> [Int] { 
    var answer:[Int] = []
    var que = prices // 큐 로

    // 빌떄까지
    while que.count > 0 {
        var cur = que.first!
        que.removeFirst()
        var cnt:Int = 0

        for q in que { // 현재 보다 작을거일때만
            cnt += 1 // 증감
            if cur > q {
                break;
            }
        }

        answer.append(cnt)
    }
    return answer
}