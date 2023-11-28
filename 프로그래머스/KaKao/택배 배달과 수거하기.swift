// 2023 KAKAO BLIND RECRUITMENT 택배 배달과 수거하기
import Foundation

func solution(_ cap:Int, _ n:Int, _ deliveries:[Int], _ pickups:[Int]) -> Int64 {
    var answer: Int64 = 0
    let deliveries = Array(deliveries.reversed())
    let pickups = Array(pickups.reversed())
    
    var currentDelivery = 0
    var currentPickup = 0
    
    for i in 0..<n {
        currentDelivery += deliveries[i]
        currentPickup += pickups[i]
        
        while currentDelivery > 0 || currentPickup > 0 {
            currentDelivery -= cap
            currentPickup -= cap

            answer += Int64((n - i) * 2)
        }
    }
    return answer
}