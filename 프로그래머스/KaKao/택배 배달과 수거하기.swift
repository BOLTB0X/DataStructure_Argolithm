// 2023 KAKAO BLIND RECRUITMENT 택배 배달과 수거하기
import Foundation

func solution(_ cap:Int, _ n:Int, _ deliveries:[Int], _ pickups:[Int]) -> Int64 {
    var answer:Int = 0
    // -> 갈땐 배달
    // <- 수거
    var dArr = deliveries
    var pArr = pickups
    
    while !dArr.isEmpty || !pArr.isEmpty {
        dArr.zeroSuffix()
        pArr.zeroSuffix()
        
        // 거리 계산
        answer += max(dArr.count, pArr.count)*2
        var state = 0
        
        // 배달 스택 업데이트
        while (!dArr.isEmpty && state < cap) {
            if dArr.last! + state <= cap {
                state += dArr.removeLast()
            } else { // cap  보다 큰 경우 가져갈수 있는 만큼만 가져감
                dArr[dArr.count-1] = dArr.last! - (cap - state)
                state += (cap - state)
            }
        }
        
        // 수거
        state = 0
        while !pArr.isEmpty && state < cap {
            if pArr.last! + state <= cap {
                state += pArr.removeLast()
            } else { // cap  보다 큰 경우 가져갈수 있는 만큼만 가져감
                pArr[pArr.count-1] = pArr.last! - (cap - state)
                state += (cap - state)
            }
        }
    }
    
    return Int64(answer)
}

extension Array where Element == Int {
    mutating func zeroSuffix() {
        while self.last ?? -1 == 0 {
            let _ = self.popLast()
        }
    }
}